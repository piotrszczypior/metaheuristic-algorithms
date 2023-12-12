#ifndef META_HEURISTIC_ALGORITHMS_ABSTRACTCOOLINGDIAGRAM_H
#define META_HEURISTIC_ALGORITHMS_ABSTRACTCOOLINGDIAGRAM_H


class AbstractCoolingDiagram {
public:
    virtual double calculate_temperature(double cooling_rate, double current_temperature, int interation_number=0) = 0;
};


#endif //META_HEURISTIC_ALGORITHMS_ABSTRACTCOOLINGDIAGRAM_H
