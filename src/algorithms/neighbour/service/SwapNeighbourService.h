#ifndef META_HEURISTIC_ALGORITHMS_SWAPNEIGHBOURSERVICE_H
#define META_HEURISTIC_ALGORITHMS_SWAPNEIGHBOURSERVICE_H

#include <vector>
#include "AbstractNeighbourService.h"

class SwapNeighbourService : public AbstractNeighbourService {

    std::vector<int> get_neighbourhood(std::vector<int> solution) override;
};

std::vector<int> SwapNeighbourService::get_neighbourhood(std::vector<int> solution) {
    int index_i = random_int(1, solution.size() - 2);
    int index_j = random_int(1, solution.size() - 2);
    std::swap(solution[index_i], solution[index_j]);

    return solution;
}


#endif //META_HEURISTIC_ALGORITHMS_SWAPNEIGHBOURSERVICE_H
