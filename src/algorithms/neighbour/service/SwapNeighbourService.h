#ifndef META_HEURISTIC_ALGORITHMS_SWAPNEIGHBOURSERVICE_H
#define META_HEURISTIC_ALGORITHMS_SWAPNEIGHBOURSERVICE_H

#include <vector>
#include "AbstractNeighbourService.h"

class SwapNeighbourService : public AbstractNeighbourService {

    std::vector<std::vector<int>> get_neighbourhood(std::vector<int> solution) override;
};

std::vector<std::vector<int>> SwapNeighbourService::get_neighbourhood(std::vector<int> solution) {
    int number_of_cities = int(solution.size());
    std::vector<std::vector<int>> neighbors;
    for (int i = 1; i < number_of_cities - 1; ++i) {
        for (int j = 1; j < number_of_cities - 1; ++j) {
            if (i != j) {
                std::vector<int> neighbor = solution;
                std::swap(neighbor[i], neighbor[j]);
                neighbors.push_back(neighbor);
            }
        }
    }
    return neighbors;
}


#endif //META_HEURISTIC_ALGORITHMS_SWAPNEIGHBOURSERVICE_H
