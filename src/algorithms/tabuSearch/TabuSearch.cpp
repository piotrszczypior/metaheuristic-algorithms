#include <chrono>
#include <random>
#include <map>
#include <list>
#include "TabuSearch.h"
#include "TabuSearchResultTO.h"
#include "../nearestNeighbour/NearestNeighbour.h"
#include "../neighbour/NeighbourServiceFactory.h"

using Edge = std::pair<int, int>;

TabuSearch::TabuSearch(Graph *graph, int max_tabu_size) {
    this->graph = graph->get_graph_as_vector();
    TABU_MAX_SIZE = max_tabu_size;
}

TabuSearchResultTO TabuSearch::process(int time_stop_criteria, NeighbourType type) {
    vector<vector<int>> tabu_list;
//    std::list<Edge> tabu_list;
    MAX_ITERATIONS_WITHOUT_IMPROVEMENT = int(graph.size() * 0.3);
    int hard_reset_max_iteration = 0;

    int iterations_without_improvement = 0;

    auto neighbour_service = NeighbourServiceFactory().create_neighbourhood_service(type);

    // find greedy_solution using greedy algorithm
    NearestNeighbour nearestNeighbour;
    auto greedy_solution = nearestNeighbour.find_solution(graph);
    long_term_memory.resize(graph.size(), vector<int>(graph.size(), 0));

    auto opt = two_opt_improvement(greedy_solution.second);
    auto current_best_cost = calculate_path_cost(opt);
    auto current_best_path = opt;

    vector<int> best_neighbour = current_best_path;

    auto start_time = std::chrono::high_resolution_clock::now();
    std::chrono::seconds duration(time_stop_criteria);
    while (std::chrono::high_resolution_clock::now() - start_time < duration) {
        vector<vector<int>> neighbourhood_solutions = neighbour_service->get_neighbourhood(best_neighbour);

        int best_neighbour_cost = numeric_limits<int>::max();
        // get candidate neighbours excluding tabu
        for (const auto &candidate_solution: neighbourhood_solutions) {
            // Check if the candidate_solution greedy_solution is better than the current best
            int candidate_cost = calculate_path_cost(candidate_solution);
            if (candidate_cost < best_neighbour_cost) {
                auto found_iterator = find(tabu_list.begin(), tabu_list.end(), candidate_solution);
                if (found_iterator == tabu_list.end() || candidate_cost < current_best_cost) {
                    best_neighbour = candidate_solution;
                    best_neighbour_cost = candidate_cost;
                }
            }
        }

        // check if greedy_solution is better
        if (best_neighbour_cost < current_best_cost) {
            current_best_path = best_neighbour;
            current_best_cost = best_neighbour_cost;
            iterations_without_improvement = 0;
        } else {
            iterations_without_improvement++;
            hard_reset_max_iteration++;
        }

        if (iterations_without_improvement >= MAX_ITERATIONS_WITHOUT_IMPROVEMENT) {
            best_neighbour = diversify_solution(best_neighbour);
            iterations_without_improvement = 0;
        }

        if (hard_reset_max_iteration >= 100) {
            best_neighbour = hard_reset(best_neighbour);
            hard_reset_max_iteration = 0;
        }

        // update Tabu list
        tabu_list.push_back(best_neighbour);
        if (tabu_list.size() > TABU_MAX_SIZE) {
            tabu_list.erase(tabu_list.begin());
        }
    }

    return {greedy_solution.first, greedy_solution.second, current_best_cost, current_best_path};
}

int TabuSearch::calculate_path_cost(vector<int> solution) {
    int cost = 0;
    for (int i = 0; i < solution.size() - 1; ++i) {
        cost += graph[solution[i]][solution[i + 1]];
    }
    return cost;
}

vector<int> TabuSearch::hard_reset(vector<int> current_solution) {
    shuffle(current_solution.begin() + 1, current_solution.end() - 1, std::mt19937(std::random_device()()));
    return current_solution;
}

vector<int> TabuSearch::diversify_solution(vector<int> current_solution) {
    current_solution.pop_back();
    current_solution.erase(current_solution.begin());
    int number_of_cities = int(current_solution.size());
    int segment_size = max(2, number_of_cities / 5);

    // Segment the solution
    vector<vector<int>> segments;
    for (int i = 0; i < number_of_cities; i += segment_size) {
        int end = min(i + segment_size, number_of_cities);
        vector<int> segment(current_solution.begin() + i, current_solution.begin() + end);
        segments.push_back(segment);
    }

    shuffle(segments.begin(), segments.end(), std::mt19937(std::random_device()()));

    vector<int> new_solution;
    new_solution.push_back(0);
    for (auto &segment: segments) {
        new_solution.insert(new_solution.end(), segment.begin(), segment.end());
    }
    new_solution.push_back(0);

    return new_solution;
}


vector<int> TabuSearch::two_opt_improvement(const vector<int> &route) {
    bool improvement = true;
    auto best_route = route;
    while (improvement) {
        improvement = false;
        for (int i = 1; i < best_route.size() - 2; i++) {
            for (int k = i + 1; k < best_route.size() - 1; k++) {
                auto new_route = best_route;
                reverse(new_route.begin() + i, new_route.begin() + k);

                if (calculate_path_cost(new_route) < calculate_path_cost(best_route)) {
                    best_route = new_route;
                    improvement = true;
                }
            }
        }
    }
    return best_route;
}
