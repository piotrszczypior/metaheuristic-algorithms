#ifndef META_HEURISTIC_ALGORITHMS_TABUSEARCHRESULTTO_H
#define META_HEURISTIC_ALGORITHMS_TABUSEARCHRESULTTO_H

#include <iostream>
#include <vector>

using namespace std;

class TabuSearchResultTO {

public:
    TabuSearchResultTO(const vector<int> &bestPath, int bestCost) : best_path(bestPath), best_cost(bestCost) {}

    int best_cost;
    vector<int> best_path;
};

#endif //META_HEURISTIC_ALGORITHMS_TABUSEARCHRESULTTO_H
