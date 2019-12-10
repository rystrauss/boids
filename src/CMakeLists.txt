set(SOURCE_FILES main.cpp Vector2D.cpp Vector2D.h Boid.cpp Boid.h)

add_executable(run_simulation ${SOURCE_FILES})
install(TARGETS run_simulation DESTINATION ${INSTALL_BIN_DIR})