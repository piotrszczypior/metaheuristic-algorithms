#include <fstream>
#include <sstream>
#include "FileReader.h"
#include "../graph/Graph.h"
#include <vector>
#include <iostream>
#include <string>
#include <regex>


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
    std::ifstream file(file_path);
    std::string line;
    std::regex edge_pattern(R"(<edge cost="([0-9.e+0-9]+)\">([0-9]+)<\/edge>)");
    std::smatch matches;
    int vertex_index = 0;

    if (!file.is_open()) {
        std::cerr << "There was a problem with xml file: " << file_path << std::endl;
        return nullptr;
    }
    vector<vector<int>> matrix;
    bool is_first_run = true;
    while (getline(file, line)) {
        if (line.find("<vertex>") != std::string::npos) {
            matrix.push_back(vector<int>());
            if (!is_first_run) {
                vertex_index++;
            }
            is_first_run = false;
        } else if (std::regex_search(line, matches, edge_pattern) && matches.size() == 3) {
            auto cost = std::stod(matches[1]);
            matrix[vertex_index].push_back(static_cast<int>(cost));
        }
    }
    return new Graph(matrix);
}


template Graph *FileReader::read_problem_from_xml_file<Graph>(std::string file_path);

template Graph *FileReader::read_problem_from_tsp_file<Graph>(std::string file_path);

std::vector<int> FileReader::read_path_from_txt_file(std::string file_path) {
    std::vector<int> cities;
    std::ifstream file(file_path);
    std::string line;
    int city_number;

    if (file.is_open()) {
        if (getline(file, line)) {
            city_number = std::stoi(line);
        }

        while (getline(file, line)) {
            cities.push_back(stoi(line));
        }
        file.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
    return cities;
}
