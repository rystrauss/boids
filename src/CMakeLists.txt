set(SOURCE_FILES main.cpp cxxopts.hpp Vector2D.cpp Vector2D.h Boid.cpp Boid.h Flock.cpp Flock.h Simulation.cpp Simulation.h KDTree.cpp KDTree.h)

add_executable(boids ${SOURCE_FILES})
find_package(SFML COMPONENTS graphics window system REQUIRED)
target_link_libraries(boids sfml-graphics sfml-window sfml-system)
install(TARGETS boids DESTINATION ${INSTALL_BIN_DIR})