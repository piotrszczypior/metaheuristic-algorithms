#include <iostream>
#include "file-reader/FileReader.h"
#include "graph/Graph.h"
#include "algorithms/tabuSearch/TabuSearch.h"
#include "algorithms/simulated-annealing/SimulatedAnnealing.h"
#include "algorithms/branchAndBound/Algorithm.h"
#include "algorithms/branchAndBound/DFSBranchBound.h"

using namespace std;

int main(int argc, char *argv[]) {
    FileReader filereader = FileReader();
    auto graph_xml = filereader.read_problem_from_tsp_file<Graph>(R"(C:\Users\Zosia\Desktop\metaheuristic-algorithms\src\rbg358.atsp)");


    SimulatedAnnealing simulatedAnnealing = {graph_xml, stod(argv[1])};
    auto result = simulatedAnnealing.process(60 * 6, stod(argv[2]));
    cout << result.best_cost << endl;
    return 0;
}