#include <iostream>
#include "file-reader/FileReader.h"
#include "graph/Graph.h"
#include "algorithms/tabuSearch/TabuSearch.h"

using namespace std;

int main(int argc, char *argv[]) {
    FileReader filereader = FileReader();

    auto graph = filereader.read_problem_from_tsp_file<Graph>("../src/br17.atsp");
    TabuSearch tabuSearch = {graph, 500};
    cout << "START" << endl;
    auto result = tabuSearch.process(50);
    cout << endl;
    cout << "cost: " << result.best_cost << endl;
    cout << "Greedy cost: " << result.greedy_cost << endl;
    cout << "Path: ";
    for (auto city: result.best_path) {
        cout << city << " ";
    }
//    graph->print();
//    cout << "Hello world!" << endl;
    getchar();
    return 0;
}