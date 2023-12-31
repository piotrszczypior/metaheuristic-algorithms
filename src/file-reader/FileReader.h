#ifndef TRAVELLING_SALESMAN_PROBLEM_FILEREADER_H
#define TRAVELLING_SALESMAN_PROBLEM_FILEREADER_H

#include <string>
#include <vector>

class FileReader {
public:
    std::vector<int> read_path_from_txt_file(std::string file_path);

    template<class T>
    T *read_problem_from_xml_file(std::string file_path);

    template<class T>
    T *read_problem_from_tsp_file(std::string file_path);
};

#endif //TRAVELLING_SALESMAN_PROBLEM_FILEREADER_H
