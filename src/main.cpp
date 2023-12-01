#include <iostream>
#include "file-reader/FileReader.h"
#include "graph/Graph.h"
#include "algorithms/tabuSearch/TabuSearch.h"

using namespace std;

int main(int argc, char *argv[]) {
    FileReader filereader = FileReader();

    auto graph_tsp = filereader.read_problem_from_tsp_file<Graph>("../src/br17.atsp")->get_graph_as_vector();
    auto graph_xml = filereader.read_problem_from_xml_file<Graph>("../src/br17.xml")->get_graph_as_vector();

    for (int i = 0; i < graph_tsp.size(); ++i) {
        for (int j = 0; j < graph_tsp.size(); ++j) {
            cout << graph_tsp[i][j] - graph_xml[i][j] << " ";
        }
    }

    cout << endl;
    cout << "LEN" << endl;
    cout << graph_tsp.size() << endl;
    cout << graph_xml.size() << endl;
//    TabuSearch tabuSearch = {graph, 500};
//    cout << "START" << endl;
//    auto result = tabuSearch.process(50);
//    cout << endl;
//    cout << "cost: " << result.best_cost << endl;
//    cout << "Greedy cost: " << result.greedy_cost << endl;
//    cout << "Path: ";
//    for (auto city: result.best_path) {
//        cout << city << " ";
//    }
//    graph->print();
//    cout << "Hello world!" << endl;
    getchar();
    return 0;
}