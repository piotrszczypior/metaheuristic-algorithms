#include <map>
#include "menu/Menu.h"
#include "file-reader/FileReader.h"
#include "graph/Graph.h"
#include "algorithms/tabuSearch/neighbour/NeighbourhoodType.h"
#include "algorithms/tabuSearch/TabuSearch.h"
#include "algorithms/simulatedAnnealing/SimulatedAnnealing.h"

using namespace std;

void test(char *argv[]);

void test_sa(char *argv[]);

int main(int argc, char *argv[]) {
//    auto graph_xml = FileReader().read_problem_from_xml_file<Graph>("../ftv55.xml");
//
//    TabuSearch tabu{graph_xml, graph_xml->get_city_number()};
//    auto result = tabu.process(120, NeighbourhoodType::Swap);
//    auto graph_xml = FileReader().read_problem_from_xml_file<Graph>("../ftv55.xml");
//
//    TabuSearch tabu{graph_xml, 5 * graph_xml->get_city_number()};
//    auto result = tabu.process(120, NeighbourhoodType::Swap);
//    cout << result.best_cost << "," << result.findTime;

//    test(argv);
    test_sa(argv);
//    menu::create_menu();
//    FileReader filereader = FileReader();
//    auto graph_xml = filereader.read_problem_from_tsp_file<Graph>(R"(../src/ftv170.atsp)");
//
//
//    SimulatedAnnealing simulatedAnnealing = {graph_xml, 0.75};
//    double  temperature = 90;
//    auto result = simulatedAnnealing.process(60 * 4, temperature);
//    TabuSearch tabuSearch = {graph_xml, 3 * graph_xml->get_city_number()};
//    auto result = tabuSearch.process(60 * 6, NeighbourhoodType::Swap);
//    cout << "Best found: " << result.best_cost << endl;
//    cout << "Greedy cost: " << result.greedy_cost << endl;
    return 0;
}

static std::map<std::string, NeighbourhoodType> const table = {{"swap",   NeighbourhoodType::Swap},
                                                               {"Insert", NeighbourhoodType::Insert},
                                                               {"Invert", NeighbourhoodType::Invert}};

// [1] file, [2] time [3] neighbour
void test(char *argv[]) {
    auto graph_xml = FileReader().read_problem_from_xml_file<Graph>(argv[1]);

    TabuSearch tabu{graph_xml, graph_xml->get_city_number()};
    auto result = tabu.process(stoi(argv[2]), table.find(argv[3])->second);
    cout << result.best_cost << "," << result.findTime;
    delete graph_xml;
}

void test_sa(char *argv[]) {
    auto graph_xml = FileReader().read_problem_from_xml_file<Graph>(argv[1]);

    SimulatedAnnealing sa{graph_xml, stod(argv[3])};
    auto result = sa.process(stoi(argv[2]));
    cout << result.best_cost << "," << result.total_time;
    delete graph_xml;
}
