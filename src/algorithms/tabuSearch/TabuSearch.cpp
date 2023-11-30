#include <chrono>
#include <random>
#include "TabuSearch.h"
#include "TabuSearchResultTO.h"
#include "../nearestNeighbour/NearestNeighbour.h"

TabuSearch::TabuSearch(Graph *graph, int max_tabu_size) {
    this->graph = graph->get_graph_as_vector();
    TABU_MAX_SIZE = max_tabu_size;
}

TabuSearchResultTO TabuSearch::process(int time_stop_criterion) {
    auto start_time = std::chrono::high_resolution_clock::now();
    std::chrono::seconds duration(time_stop_criterion);

    vector<vector<int>> tabu_list;
    MAX_ITERATIONS_WITHOUT_IMPROVEMENT = int(graph.size() * 0.35);
    int iterations_without_improvement = 0;

    // find greedy_solution using greedy algorithm
    NearestNeighbour nearestNeighbour;
    auto greedy_solution = nearestNeighbour.find_solution(graph);
    long_term_memory.resize(graph.size(), vector<int>(graph.size(), 0));
    auto current_best_cost = greedy_solution.first;
    auto current_best_path = greedy_solution.second;

    vector<int> best_neighbour = current_best_path;

    while (std::chrono::high_resolution_clock::now() - start_time < duration) {
        vector<vector<int>> neighbourhood_solutions = get_insertion_neighbourhood(best_neighbour);
        if (iterations_without_improvement == 5) {
            neighbourhood_solutions = get_inversion_neighbourhood(best_neighbour);
        }

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
            cout << "FOUND BETTER - " << current_best_cost << endl;
            iterations_without_improvement = 0;
        } else {
            iterations_without_improvement++;
        }

        if (iterations_without_improvement >= MAX_ITERATIONS_WITHOUT_IMPROVEMENT) {
            best_neighbour = diversify_solution(best_neighbour);
            iterations_without_improvement = 0;
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
    for (int i = 0; i < graph.size() - 1; ++i) {
        cost += graph[solution[i]][solution[i + 1]];
    }

    return cost;
}

vector<vector<int>> TabuSearch::get_neighbourhood_solutions(vector<int> solution) {
    vector<vector<int>> neighbors;
    int number_of_swaps = random_int(1, int(solution.size() * 0.3));

    for (int i = 0; i < number_of_swaps; ++i) {
        size_t index_i = random_int(1, solution.size() - 2);
        size_t index_j = random_int(1, solution.size() - 2);

        vector<int> neighbor = solution;
        swap(neighbor[index_i], neighbor[index_j]);
        neighbors.push_back(neighbor);
    }
    return neighbors;
}

size_t TabuSearch::random_int(int minimum, int maximum) {
    static random_device random_device;
    static mt19937 generator(random_device());
    uniform_int_distribution<int> random_index_distribution(minimum, maximum);
    return random_index_distribution(generator);
}

vector<vector<int>> TabuSearch::get_inversion_neighbourhood(vector<int> solution) {
    vector<vector<int>> neighbours;
    for (size_t i = 1; i < solution.size() - 1; ++i) {
        for (size_t j = i + 1; j < solution.size() - 1; ++j) {
            vector<int> neighbour = solution;
            reverse(neighbour.begin() + i, neighbour.begin() + j);
            neighbours.push_back(neighbour);
        }
    }
    return neighbours;
}

vector<vector<int>> TabuSearch::get_insertion_neighbourhood(vector<int> solution) {
    vector<vector<int>> neighbours;
    for (size_t i = 1; i < solution.size() - 1; ++i) {
        for (size_t j = 1; j < solution.size() - 1; ++j) {
            if (i != j) {
                vector<int> neighbour = solution;
                int removed_city = neighbour[i];
                neighbour.erase(neighbour.begin() + i);
                neighbour.insert(neighbour.begin() + j, removed_city);
                neighbours.push_back(neighbour);
            }
        }
    }
    return neighbours;
}

vector<int> TabuSearch::diversify_solution(vector<int> current_solution) {
    int number_of_cities = current_solution.size();
    int number_of_changes = std::max(1, int(number_of_cities * 0.05));

    for (int i = 0; i < number_of_changes; ++i) {
        size_t index_a = random_int(1, number_of_cities - 2);
        size_t index_b = random_int(1, number_of_cities - 2);

        while (index_a == index_b) {
            index_b = random_int(1, number_of_cities - 2);
        }

        swap(current_solution[index_a], current_solution[index_b]);
    }

    return current_solution;
}
