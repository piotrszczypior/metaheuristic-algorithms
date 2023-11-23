#include <iostream>
#include "file-reader/FileReader.h"
#include "graph/Graph.h"

using namespace std;

int main(int argc, char *argv[]) {
    FileReader filereader = FileReader();

    auto graph = filereader.read_problem_from_tsp_file<Graph>("../src/br17.atsp");
//    graph->print();
//    cout << "Hello world!" << endl;
    getchar();
    return 0;
}