cmake_minimum_required(VERSION 3.25)
project(meta-heuristic-algorithms)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

#set(CMAKE_CXX_FLAGS_RELEASE "-03")
add_executable(meta-heuristic-algorithms
        src/main.cpp
        src/graph/Graph.cpp
        src/graph/Graph.h
        src/file-writer/FileWriter.h
        src/file-writer/FileWriter.cpp
        src/file-reader/FileReader.h
        src/file-reader/FileReader.cpp
        src/menu/Menu.cpp
        src/menu/Utils.h
        src/menu/Utils.cpp
        src/algorithms/tabuSearch/TabuSearch.h
        src/algorithms/tabuSearch/TabuSearch.cpp
        src/algorithms/simulatedAnnealing/SimulatedAnnealing.h
        src/algorithms/simulatedAnnealing/SimulatedAnnealing.cpp
        src/algorithms/tabuSearch/TabuSearchResultTO.h
        src/algorithms/simulatedAnnealing/SimulatedAnnealingResultTO.h
        src/algorithms/nearestNeighbour/NearestNeighbour.cpp
        src/algorithms/nearestNeighbour/NearestNeighbour.h
        src/algorithms/tabuSearch/neighbour/NeighbourServiceFactory.h
        src/algorithms/tabuSearch/neighbour/service/AbstractNeighbourService.h
        src/algorithms/tabuSearch/neighbour/service/SwapNeighbourService.h
        src/algorithms/tabuSearch/neighbour/service/InsertNeighbourService.h
        src/algorithms/tabuSearch/neighbour/service/InverseNeighbourService.h
        src/algorithms/tabuSearch/neighbour/NeighbourhoodType.h src/algorithms/simulatedAnnealing/cooling/services/AbstractCoolingDiagram.h src/algorithms/simulatedAnnealing/cooling/services/ExponentialCoolingDiagram.h src/algorithms/simulatedAnnealing/cooling/services/GeometricCoolingDiagram.h src/algorithms/simulatedAnnealing/cooling/services/LinearCoolingDiagram.h src/algorithms/simulatedAnnealing/cooling/CoolingDiagramServiceFactory.h src/algorithms/simulatedAnnealing/cooling/CoolingDiagramType.h)
