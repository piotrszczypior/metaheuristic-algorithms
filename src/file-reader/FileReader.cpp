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
    std::ifstream file;
    file.open(file_path);
    if (!file.is_open()) {
        return nullptr;
    }
    std::string line;
    int number_of_cities = 0;

    Graph *graph = nullptr;
    std::string temporary;
    std::string city_cost_buffer;
    while (std::getline(file, line)) {
        std::istringstream string_stream(line);
        std::string token;
        string_stream >> token;

        if (token == "EOF") {
            break;
        }

        if (token == "DIMENSION:") {
            string_stream >> number_of_cities;
            graph = new Graph(number_of_cities);
        } else if (token == "EDGE_WEIGHT_SECTION") {
            for (int i = 0; i < number_of_cities; i++) {
                for (int j = 0; j < number_of_cities; ++j) {
                    file >> city_cost_buffer;
                    graph->add_new_connection(i, j, stoi(city_cost_buffer));
                }
            }
        }
    }
    return graph;
}

template<class T>
T *FileReader::read_problem_from_xml_file(std::string file_path) {
    return nullptr;
}

std::vector<std::string> FileReader::split(std::string string_to_split, char separator) {
    std::vector<std::string> result;
    std::stringstream ss(string_to_split);
    std::string item;

    while (getline(ss, item, separator)) {
        result.push_back(item);
    }
    return result;
}


template Graph *FileReader::read_problem_from_txt_file<Graph>(std::string file_path);

template Graph *FileReader::read_problem_from_xml_file<Graph>(std::string file_path);

template Graph *FileReader::read_problem_from_tsp_file<Graph>(std::string file_path);
