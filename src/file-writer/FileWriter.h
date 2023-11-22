#ifndef LIST_FILEWRITER_H
#define LIST_FILEWRITER_H

#include <string>
#include <fstream>
#include <iostream>

class FileWriter {

public:
    void write_to_file(std::string file_name, std::string value);
};



#endif //LIST_FILEWRITER_H
