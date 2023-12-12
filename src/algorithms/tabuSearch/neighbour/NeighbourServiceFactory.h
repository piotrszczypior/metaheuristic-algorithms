//
// Created by Piotr Szczypior on 07/12/2023.
//

#ifndef META_HEURISTIC_ALGORITHMS_NEIGHBOURSERVICEFACTORY_H
#define META_HEURISTIC_ALGORITHMS_NEIGHBOURSERVICEFACTORY_H

#include <optional>
#include <functional>
#include <map>
#include "service/AbstractNeighbourService.h"
#include "NeighbourhoodType.h"
#include "service/SwapNeighbourService.h"
#include "service/InsertNeighbourService.h"
#include "service/InverseNeighbourService.h"

static const std::map<NeighbourhoodType, std::function<AbstractNeighbourService *()>> NEIGHBOUR_SERVICE_MAP = {
        {NeighbourhoodType::Swap,   []() -> AbstractNeighbourService * { return new SwapNeighbourService(); }},
        {NeighbourhoodType::Insert, []() -> AbstractNeighbourService * { return new InsertNeighbourService(); }},
        {NeighbourhoodType::Invert, []() -> AbstractNeighbourService * { return new InverseNeighbourService(); }}
};

class NeighbourServiceFactory {
public:
    static AbstractNeighbourService *create_neighbourhood_service(NeighbourhoodType type) {
        auto it = NEIGHBOUR_SERVICE_MAP.find(type);
        if (it != NEIGHBOUR_SERVICE_MAP.end()) {
            return it->second();
        }
        return {};
    };
};

#endif //META_HEURISTIC_ALGORITHMS_NEIGHBOURSERVICEFACTORY_H
