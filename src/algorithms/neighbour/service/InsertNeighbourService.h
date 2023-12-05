#ifndef META_HEURISTIC_ALGORITHMS_SWAPNEIGHBOURSERVICE_H
#define META_HEURISTIC_ALGORITHMS_SWAPNEIGHBOURSERVICE_H

#include <vector>
#include "AbstractNeighbourService.h"

class InsertNeighbourService : public AbstractNeighbourService {

    std::vector<int> get_neighbourhood(std::vector<int> solution) override;
};

std::vector<int> InsertNeighbourService::get_neighbourhood(std::vector<int> solution) {
    int problem_size = int(solution.size());
    auto position_to_remove = random_int(1, problem_size - 2);
    auto selected_city = solution[position_to_remove];
    solution.erase(solution.begin() + position_to_remove);
    auto position_to_insert = random_int(1, problem_size - 2);
    while (position_to_remove == position_to_insert) {
        position_to_insert = random_int(1, problem_size - 2);
    }
    solution.insert(solution.begin() + position_to_insert, selected_city);
    return solution;
}


#endif //META_HEURISTIC_ALGORITHMS_SWAPNEIGHBOURSERVICE_H
