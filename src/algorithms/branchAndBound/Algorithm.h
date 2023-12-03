#ifndef TRAVELLING_SALESMAN_PROBLEM_ALGORITHM_H
#define TRAVELLING_SALESMAN_PROBLEM_ALGORITHM_H


#include "AlgorithmResultTO.h"

class Algorithm {
public:
    virtual AlgorithmResultTO* process() = 0;

    virtual ~Algorithm() = default;
};



#endif //TRAVELLING_SALESMAN_PROBLEM_ALGORITHM_H
