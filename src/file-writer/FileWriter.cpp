#include "FileWriter.h"

void FileWriter::write_to_file(std::string file_name, std::string value) {
    file_name += +".txt";

    std::cout << "Writing to: " << file_name << std::endl;

    std::ofstream file;
    file.open(file_name, std::ios::in | std::ios::app);

    if (file.is_open()) {
        std::string line = value + "\n";
        file << line;
    }

    file.close();
}
