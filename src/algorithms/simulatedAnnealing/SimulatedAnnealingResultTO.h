#ifndef META_HEURISTIC_ALGORITHMS_SIMULATEDANNEALINGRESULTTO_H
#define META_HEURISTIC_ALGORITHMS_SIMULATEDANNEALINGRESULTTO_H

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class SimulatedAnnealingResultTO {
public:
    SimulatedAnnealingResultTO(vector<pair<double, int>> test_result, double time, int greedyCost, const vector<int> &greedyPath, int bestCost,
                               const vector<int> &bestPath, double temperature)
            : total_time(time), greedy_cost(greedyCost), greedy_path(greedyPath), best_cost(bestCost),
              best_path(bestPath), temperature(temperature), test_result(test_result) {}

    double total_time;
    int greedy_cost;
    vector<int> greedy_path;
    int best_cost;
    vector<int> best_path;
    double temperature;
    vector<pair<double, int>> test_result;
};

#endif //META_HEURISTIC_ALGORITHMS_SIMULATEDANNEALINGRESULTTO_H
