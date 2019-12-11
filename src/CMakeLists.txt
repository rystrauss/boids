set(SOURCE_FILES main.cpp Vector2D.cpp Vector2D.h Boid.cpp Boid.h Flock.cpp Flock.h Simulation.cpp Simulation.h)

add_executable(run_simulation ${SOURCE_FILES})
find_package(SFML COMPONENTS graphics window system REQUIRED)
target_link_libraries(run_simulation sfml-graphics sfml-window sfml-system)
install(TARGETS run_simulation DESTINATION ${INSTALL_BIN_DIR})