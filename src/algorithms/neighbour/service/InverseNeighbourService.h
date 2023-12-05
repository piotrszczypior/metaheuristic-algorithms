#ifndef META_HEURISTIC_ALGORITHMS_SWAPNEIGHBOURSERVICE_H
#define META_HEURISTIC_ALGORITHMS_SWAPNEIGHBOURSERVICE_H

#include <vector>
#include "AbstractNeighbourService.h"

class InverseNeighbourService : public AbstractNeighbourService {

    std::vector<int> get_neighbourhood(std::vector<int> solution) override;
};

std::vector<int> InverseNeighbourService::get_neighbourhood(std::vector<int> solution) {
    int problem_size = int(solution.size());
    auto first_index = random_int(1, problem_size - 2);
    auto second_index = random_int(1, problem_size - 2);
    while (first_index == second_index) {
        second_index = random_int(1, problem_size - 2);
    }
    auto index_from_begin = std::min(first_index, second_index);
    auto index_from_end = std::max(first_index, second_index);

    std::reverse(solution.begin() + index_from_begin, solution.end() - index_from_end);
    return solution;
}


#endif //META_HEURISTIC_ALGORITHMS_SWAPNEIGHBOURSERVICE_H
