cmake_minimum_required(VERSION 3.25)
project(boids)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast")

set(INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(LIB_HEADERS
        src/Vector2D.h
        src/Boid.h
        src/Flock.h
        src/Simulation.h
        src/KDTree.h)

set(LIB_SOURCES
        src/Vector2D.cpp
        src/Boid.cpp
        src/Flock.cpp
        src/Simulation.cpp
        src/KDTree.cpp)

find_package(SFML CONFIG COMPONENTS graphics window system REQUIRED)
find_package(OpenMP 4.5 REQUIRED)
find_package(pybind11)

add_library(boids ${LIB_SOURCES} ${LIB_HEADERS})

target_link_libraries(boids OpenMP::OpenMP_CXX sfml-graphics sfml-window sfml-system)

add_executable(simulate src/main.cpp src/cxxopts.hpp)
target_link_libraries(simulate boids)

install(TARGETS simulate DESTINATION ${INSTALL_BIN_DIR})

if (pybind11_FOUND)
    pybind11_add_module(pyboids src/pyboids.cpp)
    target_link_libraries(pyboids PUBLIC boids)

    install(TARGETS pyboids
            COMPONENT python
            LIBRARY DESTINATION ${INSTALL_LIB_DIR})
endif ()