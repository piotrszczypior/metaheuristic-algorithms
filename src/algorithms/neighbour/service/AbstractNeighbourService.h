#ifndef META_HEURISTIC_ALGORITHMS_ABSTRACTNEIGHBOURSERVICE_H
#define META_HEURISTIC_ALGORITHMS_ABSTRACTNEIGHBOURSERVICE_H

#include <random>
#include <vector>

class AbstractNeighbourService {
public:
    static int random_int(int minimum, int maximum);

    virtual std::vector<int> get_neighbourhood(std::vector<int> solution) = 0;
};

int AbstractNeighbourService::random_int(int minimum, int maximum) {
    static std::random_device random_device;
    static std::mt19937 generator(random_device());
    std::uniform_int_distribution<int> random_index_distribution(minimum, maximum);
    return random_index_distribution(generator);
}


#endif //META_HEURISTIC_ALGORITHMS_ABSTRACTNEIGHBOURSERVICE_H
