cmake_minimum_required(VERSION 3.20)
project(Plan_recognition_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Plan_recognition_2 src/main.cpp src/headers/rule.h src/context/rule.cpp src/headers/planLibrary.h src/context/planLibrary.cpp src/headers/planRecognition.h src/solver/planRecognition.cpp)
