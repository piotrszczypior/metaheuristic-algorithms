#include "menu/Menu.h"
#include "file-reader/FileReader.h"
#include "graph/Graph.h"
#include "algorithms/simulatedAnnealing/SimulatedAnnealing.h"

using namespace std;

void test_chart_sa(char *argv[]);

int main(int argc, char *argv[]) {
    test_chart_sa(argv);
    return 0;
}


void test_chart_sa(char *argv[]) {
    auto graph_xml = FileReader().read_problem_from_xml_file<Graph>(argv[1]);
    SimulatedAnnealing sa{graph_xml, stod(argv[3])};
    auto result = sa.process(stoi(argv[2]), CoolingDiagramType::GEOMETRIC);
    cout << result.best_cost << ",[";
    for (auto measure: result.test_result) {
        cout << "(" << measure.first << "," << measure.second << "),";
    }
    cout << "]";
}