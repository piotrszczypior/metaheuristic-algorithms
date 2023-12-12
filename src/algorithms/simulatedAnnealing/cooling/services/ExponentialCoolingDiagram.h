//
// Created by Zosia on 11.12.2023.
//

#ifndef META_HEURISTIC_ALGORITHMS_EXPONENTIALCOOLINGDIAGRAM_H
#define META_HEURISTIC_ALGORITHMS_EXPONENTIALCOOLINGDIAGRAM_H

#include "AbstractCoolingDiagram.h"
#include <math.h>

class ExponentialCoolingDiagram : public AbstractCoolingDiagram {
public:
    double calculate_temperature(double cooling_rate, double current_temperature, int interation_number=0) override {
        return double(pow(cooling_rate, interation_number) * current_temperature);
    }
};

#endif //META_HEURISTIC_ALGORITHMS_EXPONENTIALCOOLINGDIAGRAM_H
