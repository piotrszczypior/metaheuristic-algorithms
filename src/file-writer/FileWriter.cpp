#include "FileWriter.h"

void FileWriter::write_to_file(std::string file_name, const std::vector<int>& path) {
    file_name += +".txt";

    std::cout << "Writing to: " << file_name << std::endl;

    std::ofstream file;
    file.open(file_name, std::ios::in | std::ios::app);
    if (file.is_open()) {
        std::cerr << "Failed to open " << file_name << '\n';
        return;
    }
    file << path.size() << '\n';

    for (auto city : path) {
        file << city << '\n';
    }
    file.close();
}
