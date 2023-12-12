//
// Created by Zosia on 11.12.2023.
//

#ifndef META_HEURISTIC_ALGORITHMS_COOLINGDIAGRAMSERVICEFACTORY_H
#define META_HEURISTIC_ALGORITHMS_COOLINGDIAGRAMSERVICEFACTORY_H

#include <optional>
#include <map>
#include <functional>
#include "CoolingDiagramType.h"
#include "services/AbstractCoolingDiagram.h"
#include "services/ExponentialCoolingDiagram.h"
#include "services/LinearCoolingDiagram.h"
#include "services/GeometricCoolingDiagram.h"

static const std::map<CoolingDiagramType, std::function<AbstractCoolingDiagram *()>> COOLING_DIAGRAM_MAP = {
        {CoolingDiagramType::GEOMETRIC,   []() -> AbstractCoolingDiagram * { return new GeometricCoolingDiagram(); }},
        {CoolingDiagramType::EXPONENTIAL, []() -> AbstractCoolingDiagram * { return new ExponentialCoolingDiagram(); }},
        {CoolingDiagramType::LINEAR,      []() -> AbstractCoolingDiagram * { return new LinearCoolingDiagram(); }}
};

class CoolingDiagramServiceFactory {
public:
    static AbstractCoolingDiagram *create_neighbourhood_service(CoolingDiagramType type) {
        auto it = COOLING_DIAGRAM_MAP.find(type);
        if (it != COOLING_DIAGRAM_MAP.end()) {
            return it->second();
        }
        return {};
    };

};


#endif //META_HEURISTIC_ALGORITHMS_COOLINGDIAGRAMSERVICEFACTORY_H
