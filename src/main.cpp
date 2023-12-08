#include <iostream>
#include "file-reader/FileReader.h"
#include "graph/Graph.h"
#include "algorithms/simulated-annealing/SimulatedAnnealing.h"
#include "algorithms/tabuSearch/TabuSearch.h"
#include "menu/Menu.h"

using namespace std;

int main(int argc, char *argv[]) {

    menu::create_menu();
//    FileReader filereader = FileReader();
//    auto graph_xml = filereader.read_problem_from_tsp_file<Graph>(R"(../src/ftv170.atsp)");
//
//
//    SimulatedAnnealing simulatedAnnealing = {graph_xml, 0.75};
//    double  temperature = 90;
//    auto result = simulatedAnnealing.process(60 * 4, temperature);
//    TabuSearch tabuSearch = {graph_xml, 3 * graph_xml->get_city_number()};
//    auto result = tabuSearch.process(60 * 6, NeighbourType::Swap);
//    cout << "Best found: " << result.best_cost << endl;
//    cout << "Greedy cost: " << result.greedy_cost << endl;
    return 0;
}