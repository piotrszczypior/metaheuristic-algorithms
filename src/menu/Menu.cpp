#include "Menu.h"
#include "../file-reader/FileReader.h"
#include "../graph/Graph.h"
#include "Utils.h"
#include "../file-writer/FileWriter.h"
#include "../algorithms/simulatedAnnealing/SimulatedAnnealing.h"
#include "../algorithms/tabuSearch/TabuSearch.h"
#include <iostream>

using namespace std;

void menu::create_menu() {
    int choice;
    int stopping_condition = 0;
    Graph *graph = nullptr;
    FileReader fileReader;
    FileWriter fileWriter;

    vector<int> solution;

    NeighbourhoodType neighbourhood;
    double temperature_coefficient;

    string buffer;

    while (true) {
        utils::clear_console();
        print_options();
        choice = utils::get_input();
        utils::clear_console();
        switch (choice) {
            case 1: {
                cout << "Enter file path: ";
                cin >> buffer;
                delete graph;
                graph = fileReader.read_problem_from_xml_file<Graph>(buffer);

                if (graph == nullptr) {
                    cout << "Reading from file was unsuccessful. Please try again..." << endl;
                    utils::press_key_to_continue();
                }
                break;
            }
            case 2: {
                if (graph == nullptr) {
                    cout << "Operation unsuccessful. Read problem from file first." << endl;
                    utils::press_key_to_continue();
                    break;
                }
                cout << "Problem visualisation as a adjacency matrix implementation of a finite graph" << endl << endl;
                graph->print();
                utils::press_key_to_continue();
                break;
            }
            case 3: {
                cout << "Enter stopping condition (time limit in seconds): ";
                stopping_condition = utils::get_input();
                break;
            }
            case 4: {
                cout << "Choose neighbourhood: " << endl;
                cout << "1. Swap   neighbourhood" << endl;
                cout << "2. Insert neighbourhood" << endl;
                cout << "3. Invert neighbourhood" << endl;
                cout << "Choice: ";
                int neighbourhood_choice = utils::get_input();

                switch (neighbourhood_choice) {
                    case 1: {
                        neighbourhood = NeighbourhoodType::Swap;
                        break;
                    }
                    case 2: {
                        neighbourhood = NeighbourhoodType::Insert;
                        break;
                    }
                    case 3: {
                        neighbourhood = NeighbourhoodType::Insert;
                        break;
                    }
                    default: {
                        neighbourhood = NeighbourhoodType::Swap;
                    }
                }
                break;
            }
            case 5: {
                cout << "Enter coefficient of temperature (should be between 0.0 - 1.0): ";
                cin >> buffer;
                temperature_coefficient = stod(buffer);
                break;
            }
            case 6: {
                if (graph == nullptr) {
                    cout << "Operation unsuccessful. Read problem from file first." << endl;
                    utils::press_key_to_continue();
                    break;
                }
                cout << "Algorithm - Tabu Search" << endl;
                TabuSearch tabuSearch = {graph, 3 * graph->get_city_number()};
                auto result = tabuSearch.process(stopping_condition, neighbourhood);
                solution = result.best_path;
                cout << "Algorithm results: " << endl;
                print_result(result.greedy_cost, result.best_cost, result.best_path);

                utils::press_key_to_continue();
                break;
            }
            case 7: {
                if (graph == nullptr) {
                    cout << "Operation unsuccessful. Read problem from file first." << endl;
                    utils::press_key_to_continue();
                    break;
                }
                CoolingDiagramType type;

                cout << "Select cooling diagram" << endl;
                cout << "1. Geometric" << endl;
                cout << "2. Linear" << endl;
                cout << "3. Exponential" << endl;
                cout << "Choice: ";

                int cooling_choice = utils::get_input();

                switch (cooling_choice) {
                    case 1: {
                        type = CoolingDiagramType::GEOMETRIC;
                        break;
                    }
                    case 2: {
                        type = CoolingDiagramType::LINEAR;
                        break;
                    }
                    case 3: {
                        type = CoolingDiagramType::EXPONENTIAL;
                        break;
                    }
                    default: {
                        type = CoolingDiagramType::GEOMETRIC;
                    }
                }

                cout << "Algorithm - Simulated Annealing" << endl;
                SimulatedAnnealing simulatedAnnealing = {graph, temperature_coefficient};
                auto result = simulatedAnnealing.process(stopping_condition, type);
                solution = result.best_path;
                print_result(result.greedy_cost, result.best_cost, result.best_path);
                cout << "Temperature K " << result.temperature << endl;
                cout << "Value of expression: " << exp(-1.00/result.temperature) << endl;

                utils::press_key_to_continue();
                break;
            }
            case 8: {
                cout << "Enter file name: ";
                cin >> buffer;
                FileWriter::write_to_file(buffer, solution);
                break;
            }
            case 9: {
                cout << "Enter file name: ";
                cin >> buffer;

                auto path = fileReader.read_path_from_txt_file(buffer);
                if(graph == nullptr) {
                    cout << "Operation unsuccessful. Read problem from file first." << endl;
                    break;
                }

                auto graph_as_vector = graph->get_graph_as_vector();
                auto cost = 0;
                for (int i = 0; i < graph_as_vector.size(); ++i) {
                    cost += graph_as_vector[path[i]][path[i+1]];
                }
                cout << "Cost of entered path: " << cost << endl;
                utils::press_key_to_continue();
                break;
            }
            case 10: {
                cout << "Quitting application..." << endl;
                delete graph;
                exit(0);
            }
            default: {
                break;
            }
        }
    }
}

void menu::print_options() {
    cout << endl;
    cout << "================================" << std::endl;
    cout << "Travelling Salesman Problem Menu" << std::endl;
    cout << "================================ " << std::endl;
    cout << "1. Read from XML file" << std::endl;
    cout << "2. Display problem as adjacency matrix graph representation" << std::endl;
    cout << "3. Enter time limit (time stopping condition)" << std::endl;
    cout << "4. Choose neighborhood for Tabu Search Algorithm" << std::endl;
    cout << "5. Choose coefficient of temperature change for Simulated Annealing" << std::endl;
    cout << "6. Algorithm - Tabu Search" << std::endl;
    cout << "7. Algorithm - Simulated Annealing" << std::endl;
    cout << "8. Save solution to .txt file" << std::endl;
    cout << "9. Read solution from file" << std::endl;
    cout << "10. Exit" << std::endl;
    cout << "Choose: ";
}

void menu::print_result(int greedy_result, int algorithm_result, const vector<int>& path) {
    cout << "----results----" << endl;
    cout << "Greedy result: " << greedy_result << endl;
    cout << "Final result: " << algorithm_result << endl;
    cout << "Path: ";
    for (auto city: path) {
        cout << city << " ";
    }
    cout << endl;
}
