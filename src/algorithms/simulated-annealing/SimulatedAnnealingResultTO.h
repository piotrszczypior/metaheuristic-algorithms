#ifndef META_HEURISTIC_ALGORITHMS_SIMULATEDANNEALINGRESULTTO_H
#define META_HEURISTIC_ALGORITHMS_SIMULATEDANNEALINGRESULTTO_H
#include <iostream>
#include <vector>

using namespace std;

class SimulatedAnnealingResultTO {

public:
    SimulatedAnnealingResultTO(const vector<int> &bestPath, int bestCost) : best_path(bestPath), best_cost(bestCost) {}

    int best_cost;
    vector<int> best_path;
};
#endif //META_HEURISTIC_ALGORITHMS_SIMULATEDANNEALINGRESULTTO_H
