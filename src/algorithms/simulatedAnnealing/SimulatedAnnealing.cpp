#include <chrono>
#include <random>
#include "SimulatedAnnealing.h"
#include "../nearestNeighbour/NearestNeighbour.h"
#include "cooling/CoolingDiagramServiceFactory.h"
#include <numeric>

using namespace std;

SimulatedAnnealingResultTO SimulatedAnnealing::process(int time_stop_criteria, CoolingDiagramType type) {
    NearestNeighbour nearestNeighbour = {};
    auto nearestNeighbourSolution = nearestNeighbour.find_solution(graph);
    auto best_cost = nearestNeighbourSolution.first;
    auto best_path = nearestNeighbourSolution.second;
    auto current_path = best_path;
    problem_size = int(best_path.size());
    double temperature = calculate_initial_temperature();
    auto iteration_number = 0;
    auto coolingDiagram = CoolingDiagramServiceFactory::create_neighbourhood_service(CoolingDiagramType::GEOMETRIC);


    //TODO: zu entfernen
    vector<pair<double, int>> test_result;
    test_result.emplace_back(0.0, best_cost);

    auto start_time = std::chrono::high_resolution_clock::now();
    std::chrono::seconds duration(time_stop_criteria);
    auto time = std::chrono::high_resolution_clock::now();
    auto best_path_time = start_time;
    while (std::chrono::high_resolution_clock::now() - start_time < duration) {
        for (int i = 0; i < 5; ++i) {
            auto neighbour = get_neighbours(current_path);
            auto neighbour_cost = calculate_path_cost(neighbour);

            if (accept_move(best_cost, neighbour_cost, temperature)) {
                current_path = neighbour;

                if (neighbour_cost < best_cost) {
                    best_path = neighbour;
                    best_cost = neighbour_cost;
                    auto measure_time = std::chrono::duration<double>(
                            std::chrono::high_resolution_clock::now() - start_time).count();
                    test_result.emplace_back(measure_time, best_cost);
                }
            }

        }

        temperature = coolingDiagram->calculate_temperature(COOLING_RATE, temperature, iteration_number);
        iteration_number++;
    }

    auto total_time = std::chrono::duration<double>(best_path_time - start_time).count();
    return {test_result, total_time, nearestNeighbourSolution.first, nearestNeighbourSolution.second, best_cost,
            best_path, temperature};
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
            break;

        case 1:
            make_inverse_move(solution);
            break;

        case 2:
            make_insert_move(solution);
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

double SimulatedAnnealing::calculate_initial_temperature() {
    const int SAMPLE_NUMBER = 10000;
    vector<double> deltas;
    deltas.reserve(SAMPLE_NUMBER);

    for (int i = 0; i < SAMPLE_NUMBER; ++i) {
        auto solution = generate_random_solution();
        auto neighbour = get_neighbours(solution);
        auto current_cost = calculate_path_cost(solution);
        auto neighbour_cost = calculate_path_cost(neighbour);
        deltas.push_back(abs(current_cost - neighbour_cost));
    }

    std::nth_element(deltas.begin(), deltas.begin() + deltas.size() / 2, deltas.end());
    double median_delta = deltas[deltas.size() / 2];

    const double P = 0.85;
    double initial_temperature = -median_delta / log(P);

//    cout << "Initial temperature: " << initial_temperature << endl;
    return initial_temperature;
}

vector<int> SimulatedAnnealing::generate_random_solution() {
    vector<int> solution(graph.size() + 1);
    iota(solution.begin(), solution.end() - 1, 0);
    solution.push_back(0);
    shuffle(solution.begin() + 1, solution.end() - 1, generator);

    return solution;
}

