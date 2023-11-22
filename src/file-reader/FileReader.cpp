#include <fstream>
#include <sstream>
#include "FileReader.h"
#include "../graph/Graph.h"

template<class T>
T *FileReader::read_problem_from_txt_file(std::string file_path) {
    std::ifstream file;
    file.open(file_path);

    if (!file.is_open()) {
        return nullptr;
    }
    std::string line;
    std::string city_cost;
    std::getline(file, line);
    int city_number = std::stoi(line);

    auto graph = new Graph(city_number);

    for (int i = 0; i < city_number; i++) {
        std::getline(file, line);
        std::stringstream stream(line);
        for (int j = 0; j < city_number; ++j) {
            stream >> city_cost;
            graph->add_new_connection(i, j, stoi(city_cost));
        }
    }

    return graph;
}

template<class T>
T *FileReader::read_problem_from_tsp_file(std::string file_path) {
    return nullptr;
}

template<class T>
T *FileReader::read_problem_from_xml_file(std::string file_path) {
    return nullptr;
}

template Graph *FileReader::read_problem_from_txt_file<Graph>(std::string file_path);
template Graph *FileReader::read_problem_from_xml_file<Graph>(std::string file_path);
template Graph *FileReader::read_problem_from_tsp_file<Graph>(std::string file_path);