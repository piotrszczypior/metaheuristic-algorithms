#include "Menu.h"
#include "../file-reader/FileReader.h"
#include "../graph/Graph.h"
#include "Utils.h"
#include "../file-writer/FileWriter.h"
#include <iostream>

using namespace std;

void menu::create_menu() {
    int choice;
    int stopping_condition = 0;
    Graph *graph = nullptr;
    FileReader fileReader;
    FileWriter fileWriter;
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
                graph = fileReader.read_problem_from_tsp_file<Graph>(buffer);

                if (graph == nullptr) {
                    cout << "Reading from file was unsuccessful. Please try again..." << endl;
                    utils::press_key_to_continue();
                }
                break;
            }
            case 2: {
                if (graph == nullptr) {
                    cout << "Operation unsuccessful. Generate or read problem from file first." << endl;
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
            }
            case 4: {
                // TODO: choose neighbourhood
                break;
            }
            case 5: {
                // TODO: choose coefficient of temperature change
                break;
            }
            case 6: {
                if (graph == nullptr) {
                    cout << "Operation unsuccessful. Generate or read problem from file first." << endl;
                    utils::press_key_to_continue();
                    break;
                }
                cout << "Algorithm - Tabu Search" << endl;
                // TODO: implementation

                cout << "Algorithm results: " << endl;
                utils::press_key_to_continue();
                break;
            }
            case 7: {
                if (graph == nullptr) {
                    cout << "Operation unsuccessful. Generate or read problem from file first." << endl;
                    utils::press_key_to_continue();
                    break;
                }
                cout << "Algorithm - Simulated Annealing" << endl;
                // TODO: implementation

                cout << "Algorithm results: " << endl;
                utils::press_key_to_continue();
                break;
            }
            case 8: {
                cout << "Enter file name: ";
                cin >> buffer;
                // TODO - parse result to string
                fileWriter.write_to_file(buffer, "TODO - result");
                cout << "Saving solution to "<< buffer << " .txt file" << endl;
                break;
            }
            case 9: {
                // TODO: Read solution from file
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
    cout << "1. Read from file" << std::endl;
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
