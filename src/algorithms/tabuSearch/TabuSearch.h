

#ifndef META_HEURISTIC_ALGORITHMS_TABUSEARCH_H
#define META_HEURISTIC_ALGORITHMS_TABUSEARCH_H

#include <vector>
#include "../../graph/Graph.h"
#include "TabuSearchResultTO.h"

using namespace std;

class TabuSearch {
private:
    int TABU_MAX_SIZE;
    int MAX_ITERATIONS_WITHOUT_IMPROVEMENT;
    vector<vector<int>> graph;
    int **tabu_list;
    vector<vector<int>> long_term_memory;
    pair<int, vector<int>> find_solution_using_nearest_neighbour();

public:
    TabuSearch(Graph *graph, int max_tabu_size);

    TabuSearchResultTO process(int time_stop_criterion);

    int calculate_path_cost(vector<int> solution);

    vector<vector<int>> get_neighbourhood_solutions(vector<int> solution);

    vector<vector<int>> get_inversion_neighbourhood(vector<int> solution);

    vector<vector<int>> get_insertion_neighbourhood(vector<int> solution);

    size_t random_int(int minimum, int maximum);

    vector<int> diversify_solution(vector<int> current_solution);
};


#endif //META_HEURISTIC_ALGORITHMS_TABUSEARCH_H
