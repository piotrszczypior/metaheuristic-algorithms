#ifndef META_HEURISTIC_ALGORITHMS_ABSTRACTNEIGHBOURSERVICE_H
#define META_HEURISTIC_ALGORITHMS_ABSTRACTNEIGHBOURSERVICE_H

#include <random>
#include <vector>

class AbstractNeighbourService {
public:
    virtual ~AbstractNeighbourService() = default;

    virtual std::vector<std::vector<int>> get_neighbourhood(std::vector<int> solution) = 0;
};

#endif //META_HEURISTIC_ALGORITHMS_ABSTRACTNEIGHBOURSERVICE_H
