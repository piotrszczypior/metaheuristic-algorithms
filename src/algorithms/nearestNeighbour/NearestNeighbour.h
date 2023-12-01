#ifndef META_HEURISTIC_ALGORITHMS_NEARESTNEIGHBOUR_H
#define META_HEURISTIC_ALGORITHMS_NEARESTNEIGHBOUR_H

#include <vector>

using namespace std;

class NearestNeighbour {
public:
   pair<int, vector<int>> find_solution(vector<vector<int>> graph);
};


#endif //META_HEURISTIC_ALGORITHMS_NEARESTNEIGHBOUR_H
