

#ifndef META_HEURISTIC_ALGORITHMS_SIMULATEDANNEALING_H
#define META_HEURISTIC_ALGORITHMS_SIMULATEDANNEALING_H


#include "SimulatedAnnealingResultTO.h"
#include "../../graph/Graph.h"
#include <random>

class SimulatedAnnealing {
private:
    double COOLING_RATE;
    int problem_size;
    std::mt19937 generator{std::random_device{}()};
    vector<vector<int>> graph;

    int random_int(int minimum, int maximum);

    vector<int> get_neighbours(vector<int> solution);

    void make_swap_cities_move(vector<int> &neighbour);

    void make_inverse_move(vector<int> &neighbour);

    void make_insert_move(vector<int> &neighbour);

    bool accept_move(int current_best_cost, int neighbour_cost, double temperature);

    int calculate_path_cost(const vector<int> &solution);

    double calculate_initial_temperature();

public:

    SimulatedAnnealing(Graph *graph, double cooling_rate);

    SimulatedAnnealingResultTO process(int time_stop_criteria);

    vector<int> generate_random_solution();
};


#endif //META_HEURISTIC_ALGORITHMS_SIMULATEDANNEALING_H
