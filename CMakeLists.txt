cmake_minimum_required(VERSION 3.25)
project(meta-heuristic-algorithms)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

#set(CMAKE_CXX_FLAGS_RELEASE "-03")
add_executable(meta-heuristic-algorithms
        src/main.cpp
        src/graph/Graph.cpp
        src/graph/Graph.h
        src/file-writer/FileWriter.h
        src/file-writer/FileWriter.cpp
        src/file-reader/FileReader.h src/file-reader/FileReader.cpp)