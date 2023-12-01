#ifndef META_HEURISTIC_ALGORITHMS_TABUSEARCHRESULTTO_H
#define META_HEURISTIC_ALGORITHMS_TABUSEARCHRESULTTO_H

#include <iostream>
#include <vector>

using namespace std;

class TabuSearchResultTO {

public:
    TabuSearchResultTO(int greedyCost, const vector<int> &greedySolution, int bestCost, const vector<int> &bestPath)
            : greedy_cost(greedyCost), greedy_solution(greedySolution), best_cost(bestCost), best_path(bestPath) {}

    int greedy_cost;
    vector<int> greedy_solution;

    int best_cost;
    vector<int> best_path;
};

#endif //META_HEURISTIC_ALGORITHMS_TABUSEARCHRESULTTO_H
