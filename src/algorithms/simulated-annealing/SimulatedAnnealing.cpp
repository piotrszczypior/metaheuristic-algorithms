#include <chrono>
#include <random>
#include "SimulatedAnnealing.h"
#include "../nearestNeighbour/NearestNeighbour.h"

using namespace std;

SimulatedAnnealingResultTO SimulatedAnnealing::process(int time_stop_criteria, double temperature) {
    NearestNeighbour nearestNeighbour = {};
    auto nearestNeighbourSolution = nearestNeighbour.find_solution(graph);
    auto best_cost = nearestNeighbourSolution.first;
    auto best_path = nearestNeighbourSolution.second;
    auto current_path = best_path;
    problem_size = best_path.size();

    auto start_time = std::chrono::high_resolution_clock::now();
    std::chrono::seconds duration(time_stop_criteria);

    while (std::chrono::high_resolution_clock::now() - start_time < duration) {
        auto neighbour = get_neighbours(current_path);
        auto neighbour_cost = calculate_path_cost(neighbour);

        if (accept_move(best_cost, neighbour_cost, temperature)) {
            current_path = neighbour;

            if (neighbour_cost < best_cost) {
                best_path = neighbour;
                best_cost = neighbour_cost;
            }
        }
        temperature *= COOLING_RATE;
    }

//    cout << "Move insert: " << move_insert << endl;
//    cout << "Move swap: " << move_swap << endl;
//    cout << "Move inverse: " << move_inverse << endl;
//
//    cout << "value of expression: " << exp(-1/temperature) << endl;
//    cout << "Temperature: " << temperature << endl;

    return {best_path, best_cost};
}

SimulatedAnnealing::SimulatedAnnealing(Graph *graph, double cooling_rate) {
    this->graph = graph->get_graph_as_vector();
    this->COOLING_RATE = cooling_rate;
}

vector<int> SimulatedAnnealing::get_neighbours(vector<int> solution) {
    int move_index = random_int(0, 2);

    switch (move_index) {
        case 0:
            make_swap_cities_move(solution);
            move_swap++;
            break;

        case 1:
            make_inverse_move(solution);
            move_inverse++;
            break;

        case 2:
            make_insert_move(solution);
            move_insert++;
            break;
    }
    return solution;
}

int SimulatedAnnealing::random_int(int minimum, int maximum) {
    uniform_int_distribution<int> random_index_distribution(minimum, maximum);
    return random_index_distribution(generator);
}

void SimulatedAnnealing::make_swap_cities_move(vector<int> &neighbour) {
    auto first_position = random_int(1, problem_size - 2);
    auto second_position = random_int(1, problem_size - 2);

    while (first_position == second_position) {
        second_position = random_int(1, problem_size - 2);
    }
    swap(neighbour[first_position], neighbour[second_position]);
}

void SimulatedAnnealing::make_swap_route_parts_move(vector<int> &neighbour) {
    auto first_position = random_int(1, problem_size - 2);
    auto second_position = random_int(1, problem_size - 2);

    auto begin_positions_iterator = neighbour.begin() + min(first_position, second_position);
    auto end_positions_iterator = neighbour.begin() + max(first_position, second_position);
    auto sub_route = vector<int>(begin_positions_iterator, end_positions_iterator);
    neighbour.erase(begin_positions_iterator, end_positions_iterator);

    auto new_size = neighbour.size();
    auto new_position_of_route_part = random_int(1, new_size - 1);

    for (auto city : sub_route) {
        neighbour.insert(neighbour.begin() + new_position_of_route_part++, city);
    }
}

void SimulatedAnnealing::make_inverse_move(vector<int> &neighbour) {
    auto first_index = random_int(1, problem_size - 2);
    auto second_index = random_int(1, problem_size - 2);
    while (first_index == second_index) {
        second_index = random_int(1, problem_size - 2);
    }
    auto index_from_begin = min(first_index, second_index);
    auto index_from_end = max(first_index, second_index);

    std::reverse(neighbour.begin() + index_from_begin, neighbour.end() - index_from_end);
}

void SimulatedAnnealing::make_insert_move(vector<int> &neighbour) {
    auto position_to_remove = random_int(1, problem_size - 2);
    auto selected_city = neighbour[position_to_remove];
    neighbour.erase(neighbour.begin() + position_to_remove);
    auto position_to_insert = random_int(1, problem_size - 2);
    while (position_to_remove == position_to_insert) {
        position_to_insert = random_int(1, problem_size - 2);
    }
    neighbour.insert(neighbour.begin() + position_to_insert, selected_city);
}

bool SimulatedAnnealing::accept_move(int current_best_cost, int neighbour_cost, double temperature) {
    if (current_best_cost > neighbour_cost) {
        return true;
    }
    double probability = exp((current_best_cost - neighbour_cost) / temperature);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    return distribution(generator) < probability;
}

int SimulatedAnnealing::calculate_path_cost(const vector<int> &solution) {
    int cost = 0;
    for (int i = 0; i < problem_size - 1; ++i) {
        cost += graph[solution[i]][solution[i + 1]];
    }
    return cost;
}

