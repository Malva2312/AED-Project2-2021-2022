cmake_minimum_required(VERSION 3.20)
project(TrabalhoAED2)

set(CMAKE_CXX_STANDARD 11)

add_executable(TrabalhoAED2 main.cpp Classes/Stop.cpp Classes/Stop.h UI/Menu.cpp UI/Menu.h Classes/Coordinates.h Classes/Coordinates.cpp Classes/Program.cpp Classes/Program.h MyGraph.cpp MyGraph.h)
