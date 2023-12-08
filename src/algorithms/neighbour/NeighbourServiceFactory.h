//
// Created by Piotr Szczypior on 07/12/2023.
//

#ifndef META_HEURISTIC_ALGORITHMS_NEIGHBOURSERVICEFACTORY_H
#define META_HEURISTIC_ALGORITHMS_NEIGHBOURSERVICEFACTORY_H

#include <optional>
#include "service/AbstractNeighbourService.h"
#include "NeighbourhoodType.h"
#include "service/SwapNeighbourService.h"
#include "service/InsertNeighbourService.h"
#include "service/InverseNeighbourService.h"

class NeighbourServiceFactory {
public:
    static AbstractNeighbourService* create_neighbourhood_service(NeighbourType type) {
        switch (type) {
            case NeighbourType::Swap:
                return new SwapNeighbourService();

            case NeighbourType::Insert:
                return new InsertNeighbourService();

            case NeighbourType::Invert:
                return new InverseNeighbourService();
        }
        return {};
    }
};

#endif //META_HEURISTIC_ALGORITHMS_NEIGHBOURSERVICEFACTORY_H
