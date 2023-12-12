//
// Created by Zosia on 11.12.2023.
//

#ifndef META_HEURISTIC_ALGORITHMS_LINEARCOOLINGDIAGRAM_H
#define META_HEURISTIC_ALGORITHMS_LINEARCOOLINGDIAGRAM_H


#include "AbstractCoolingDiagram.h"

class LinearCoolingDiagram : public AbstractCoolingDiagram {
public:
    double calculate_temperature(double cooling_rate, double current_temperature, int interation_number=0) override {
        return current_temperature - cooling_rate;
    }
};


#endif //META_HEURISTIC_ALGORITHMS_LINEARCOOLINGDIAGRAM_H
