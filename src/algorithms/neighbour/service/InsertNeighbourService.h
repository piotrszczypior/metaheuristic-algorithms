#ifndef META_HEURISTIC_ALGORITHMS_INSERTNEIGHBOURSERVICE_H
#define META_HEURISTIC_ALGORITHMS_INSERTNEIGHBOURSERVICE_H

#include <vector>
#include "AbstractNeighbourService.h"

class InsertNeighbourService : public AbstractNeighbourService {

    std::vector<std::vector<int>> get_neighbourhood(std::vector<int> solution) override;
};

std::vector<std::vector<int>> InsertNeighbourService::get_neighbourhood(std::vector<int> solution) {
    std::vector<std::vector<int>> neighbours;
    for (int i = 1; i < solution.size() - 1; ++i) {
        for (int j = 1; j < solution.size() - 1; ++j) {
            if (i != j) {
                std::vector<int> neighbour = solution;
                int removed_city = neighbour[i];
                neighbour.erase(neighbour.begin() + i);
                neighbour.insert(neighbour.begin() + j, removed_city);
                neighbours.push_back(neighbour);
            }
        }
    }
    return neighbours;
}


#endif //META_HEURISTIC_ALGORITHMS_INSERTNEIGHBOURSERVICE_H
