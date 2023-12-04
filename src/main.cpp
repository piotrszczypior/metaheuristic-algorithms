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
    auto graph_xml = filereader.read_problem_from_tsp_file<Graph>(R"(src\ftv170.atsp)");


    SimulatedAnnealing simulatedAnnealing = {graph_xml, stod(argv[1])};
    double  temperature = 358 * 0.20;
    auto result = simulatedAnnealing.process(60 * 6, temperature);
    cout << result.best_cost << endl;
    return 0;
}