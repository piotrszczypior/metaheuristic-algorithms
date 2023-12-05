#ifndef META_HEURISTIC_ALGORITHMS_SIMULATEDANNEALINGRESULTTO_H
#define META_HEURISTIC_ALGORITHMS_SIMULATEDANNEALINGRESULTTO_H
#include <iostream>
#include <vector>

using namespace std;

class SimulatedAnnealingResultTO {
public:
    SimulatedAnnealingResultTO(int greedyCost, const vector<int> &greedyPath, int bestCost, const vector<int> &bestPath)
            : greedy_cost(greedyCost), greedy_path(greedyPath), best_cost(bestCost), best_path(bestPath) {}

    int greedy_cost;
    vector<int> greedy_path;
    int best_cost;
    vector<int> best_path;
};
#endif //META_HEURISTIC_ALGORITHMS_SIMULATEDANNEALINGRESULTTO_H
