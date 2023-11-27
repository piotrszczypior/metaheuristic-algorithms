

#include <chrono>
#include <random>
#include "TabuSearch.h"
#include "TabuSearchResultTO.h"

TabuSearch::TabuSearch(Graph *graph, int max_tabu_size) {
    this->graph = graph->get_graph_as_vector();
    TABU_MAX_SIZE = max_tabu_size;
}

pair<int, vector<int>> TabuSearch::find_solution_using_nearest_neighbour() {
    int number_of_cities = graph.size();
    vector<bool> visited_cities(number_of_cities, false);
    int current_city = 0;
    visited_cities[current_city] = true;
    int next_nearest_city = 0;
    vector<int> nearest_neighbour_path(number_of_cities + 1, 0);
    int minimum_distance = INT_MAX;
    int path_cost = 0;

    for (int i = 1; i < number_of_cities; ++i) {
        minimum_distance = INT_MAX;
        for (int next_city = 0; next_city < number_of_cities; ++next_city) {
            if (graph[current_city][next_city] < minimum_distance && !visited_cities[next_city]) {
                minimum_distance = graph[current_city][next_city];
                next_nearest_city = next_city;
            }
        }
        nearest_neighbour_path[i] = next_nearest_city;
        path_cost += minimum_distance;
        current_city = next_nearest_city;
        visited_cities[current_city] = true;
    }
    path_cost += graph[current_city][0];

    return make_pair(path_cost, nearest_neighbour_path);
}

TabuSearchResultTO TabuSearch::process(int time_stop_criterion) {
    auto start_time = std::chrono::high_resolution_clock::now();
    std::chrono::seconds duration(time_stop_criterion);

    vector<vector<int>> tabu_list;

    // find solution using greedy algorithm
    auto solution = find_solution_using_nearest_neighbour();
    auto current_best_cost = solution.first;
    auto current_best_path = solution.second;
    cout << "Greedy: ";
    for (auto city : current_best_path) {
        cout << city << " ";
    }
    cout << "\n";
    cout << current_best_cost;

    while (std::chrono::high_resolution_clock::now() - start_time < duration) {
        vector<vector<int>> neighbourhood_solutions = get_neighbourhood_solutions(current_best_path);

        int best_neighbour_cost = numeric_limits<int>::max();
        vector<int> best_neighbour;

        // get candidate neighbours excluding tabu
        for (const auto& candidate : neighbourhood_solutions) {
            // Check if the candidate solution is better than the current best
            int candidate_cost = calculate_path_cost(candidate);
            if (candidate_cost < best_neighbour_cost && find(tabu_list.begin(), tabu_list.end(), candidate) == tabu_list.end()) {
                // get best neighbour from neighbours
                best_neighbour = candidate;
                best_neighbour_cost = candidate_cost;
            }
        }

        // check if solution is better
        if (best_neighbour_cost < current_best_cost) {
            current_best_path = best_neighbour;
            current_best_cost = best_neighbour_cost;
        }

        // update Tabu list
        tabu_list.push_back(best_neighbour);
        if (tabu_list.size() > TABU_MAX_SIZE) {
            tabu_list.erase(tabu_list.begin());
        }
    }

    return TabuSearchResultTO{current_best_path, current_best_cost};
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

    for (size_t i = 0; i < solution.size() - 1; ++i) {
        for (size_t j = i + 1; j < solution.size(); ++j) {
            // Create a copy of the current solution and swap cities i and j
            size_t index_i = random_int(0, solution.size() - 1);
            size_t index_j = random_int(0, solution.size() - 1);

            vector<int> neighbor = solution;
            swap(neighbor[index_i], neighbor[index_j]);
            neighbors.push_back(neighbor);
        }
    }
    return neighbors;
}

size_t TabuSearch::random_int(int minimum, int maximum) {
    static random_device random_device;
    static mt19937 generator(random_device());
    uniform_int_distribution<int> random_index_distribution(minimum, maximum);
    return random_index_distribution(generator);
}
