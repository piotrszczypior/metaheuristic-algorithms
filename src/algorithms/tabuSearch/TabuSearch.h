

#ifndef META_HEURISTIC_ALGORITHMS_TABUSEARCH_H
#define META_HEURISTIC_ALGORITHMS_TABUSEARCH_H

#include <vector>
#include <random>
#include "../../graph/Graph.h"
#include "TabuSearchResultTO.h"
#include "neighbour/NeighbourhoodType.h"

using namespace std;

class TabuSearch {
private:
    int TABU_MAX_SIZE;
    int MAX_ITERATIONS_WITHOUT_IMPROVEMENT{};
    vector<vector<int>> graph;
    std::mt19937 generator{std::random_device{}()};


    int calculate_path_cost(vector<int> solution);

    vector<int> diversify_solution(vector<int> current_solution);

    vector<int> two_opt_improvement(const vector<int> &route);

    vector<int> hard_reset(vector<int> current_solution);

    vector<int> generate_random_solution();

public:

    TabuSearch(Graph *graph, int max_tabu_size);

    TabuSearchResultTO process(int time_stop_criteria, NeighbourhoodType type);
};


#endif //META_HEURISTIC_ALGORITHMS_TABUSEARCH_H
