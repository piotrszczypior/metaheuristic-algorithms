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

    auto graph_tsp = filereader.read_problem_from_tsp_file<Graph>("../src/ftv170.atsp");
    auto graph_txt = filereader.read_problem_from_txt_file<Graph>("../src/test.txt")->get_graph_as_vector();
    auto graph_xml = filereader
            .read_problem_from_xml_file<Graph>("../src/br17.xml");
    cout << "START" << endl;

//    TabuSearch tabuSearch = {graph_xml, 500};
//    auto result = tabuSearch.process(50);

//    for (auto x: graph_xml->get_graph_as_vector()[16]) {
//        cout << x << " ";
//    }

    double temp_rate = 0.99;
    SimulatedAnnealing simulatedAnnealing = {graph_tsp, temp_rate};
    auto result = simulatedAnnealing.process(240, 1000);


    cout << endl;
    cout << "cost: " << result.best_cost << endl;
//    cout << "Greedy cost: " << result.greedy_cost << endl;
    cout << "Path: ";
    for (auto city: result.best_path) {
        cout << city << " ";
    }
    getchar();
    return 0;
}