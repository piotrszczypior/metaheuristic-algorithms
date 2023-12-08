#ifndef META_HEURISTIC_ALGORITHMS_INVERSENEIGHBOURSERVICE_H
#define META_HEURISTIC_ALGORITHMS_INVERSENEIGHBOURSERVICE_H

#include <vector>
#include "AbstractNeighbourService.h"

class InverseNeighbourService : public AbstractNeighbourService {

    std::vector<std::vector<int>> get_neighbourhood(std::vector<int> solution) override;
};

std::vector<std::vector<int>> InverseNeighbourService::get_neighbourhood(std::vector<int> solution) {
    std::vector<std::vector<int>> neighbours;
    for (int i = 1; i < solution.size() - 2; ++i) {
        for (int j = i + 1; j < solution.size() - 1; ++j) {
            std::vector<int> neighbour = solution;
            reverse(neighbour.begin() + i, neighbour.begin() + j - 1);
            neighbours.push_back(neighbour);
        }
    }
    return neighbours;
}


#endif //META_HEURISTIC_ALGORITHMS_INVERSENEIGHBOURSERVICE_H
