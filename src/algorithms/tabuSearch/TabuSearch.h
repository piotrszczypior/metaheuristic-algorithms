

#ifndef META_HEURISTIC_ALGORITHMS_TABUSEARCH_H
#define META_HEURISTIC_ALGORITHMS_TABUSEARCH_H

#include <vector>
#include "../../graph/Graph.h"
#include "TabuSearchResultTO.h"
#include "../neighbour/NeighbourhoodType.h"

using namespace std;

class TabuSearch {
private:
    int TABU_MAX_SIZE;
    int MAX_ITERATIONS_WITHOUT_IMPROVEMENT{};
    vector<vector<int>> graph;
    vector<vector<int>> long_term_memory;

    int calculate_path_cost(vector<int> solution);

    static vector<vector<int>> get_neighbourhood_solutions(const vector<int> &solution);

    vector<vector<int>> get_inversion_neighbourhood(vector<int> solution);

    static vector<vector<int>> get_insertion_neighbourhood(const vector<int> &solution);

    static size_t random_int(int minimum, int maximum);

    static vector<int> diversify_solution(vector<int> current_solution);

    vector<int> two_opt_improvement(const vector<int> &route);

    static vector<int> hard_reset(vector<int> current_solution);

public:

    TabuSearch(Graph *graph, int max_tabu_size);

    TabuSearchResultTO process(int time_stop_criteria, NeighbourType type);
};


#endif //META_HEURISTIC_ALGORITHMS_TABUSEARCH_H
