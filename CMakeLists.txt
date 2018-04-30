cmake_minimum_required(VERSION 3.1.3)

project(Projet-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11) # Use C++11

set(CMAKE_BUILD_TYPE Debug)

add_executable(main main.cpp Bacterie.cpp Bacterie.h Lignee_L.cpp Lignee_L.h Lignee_S.cpp Lignee_S.h Case.cpp Case.h Environnement.cpp Environnement.h)

