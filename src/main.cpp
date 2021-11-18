#include <string>
#include <iostream>
#include "Simulation.h"
#include "cxxopts.hpp"

int main(int argc, char **argv) {
    cxxopts::Options options("boids", "Runs a simulation of Craig Reynolds' boids program.");

    options.add_options()
            ("width", "Width of the window.",
             cxxopts::value<int>()->default_value(std::to_string(Simulation::DEFAULT_WINDOW_WIDTH)))
            ("height", "Height of the window.",
             cxxopts::value<int>()->default_value(std::to_string(Simulation::DEFAULT_WINDOW_HEIGHT)))
            ("boid_size", "The size of the boids.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_BOID_SIZE)))
            ("max_speed", "Maximum speed of a boid.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_MAX_SPEED)))
            ("max_force", "Maximum force that can be applied to a boid.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_MAX_FORCE)))
            ("flock_size", "Initial size of the flock.",
             cxxopts::value<int>()->default_value(std::to_string(Simulation::DEFAULT_FLOCK_SIZE)))
            ("alignment_weight", "Weight applied to the alignment rule.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_ALIGNMENT_WEIGHT)))
            ("cohesion_weight", "Weight applied to the cohesion rule.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_COHESION_WEIGHT)))
            ("separation_weight", "Weight applied to the separation rule.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_SEPARATION_WEIGHT)))
            ("acceleration_scale", "Scaling factor applied to boids' acceleration.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_ACCELERATION_SCALE)))
            ("perception", "Boids consider other boids within this range when deciding how to act.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_PERCEPTION)))
            ("separation_distance", "The minimum distance boids will try to stay away from each other.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_SEPARATION_DISTANCE)))
            ("noise_scale", "The scaling factor that controls the amount of noise to be added to boid's movements.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_NOISE_SCALE)))
            ("num_threads", "Number of threads to use for parallelization.",
             cxxopts::value<int>()->default_value(std::to_string(-1)))
            ("fullscreen", "Runs the simulation in a fullscreen window.")
            ("light_scheme", "Uses a light color scheme.")
            ("help", "Displays this help message.");

    auto result = options.parse(argc, argv);

    if (result["help"].as<bool>()) {
        std::cout << options.help() << std::endl;
        return EXIT_SUCCESS;
    }

    Simulation simulation(result["width"].as<int>(), result["height"].as<int>(), result["boid_size"].as<float>(),
                          result["max_speed"].as<float>(), result["max_force"].as<float>(),
                          result["alignment_weight"].as<float>(), result["cohesion_weight"].as<float>(),
                          result["separation_weight"].as<float>(), result["acceleration_scale"].as<float>(),
                          result["perception"].as<float>(), result["separation_distance"].as<float>(),
                          result["noise_scale"].as<float>(), result["fullscreen"].as<bool>(),
                          result["light_scheme"].as<bool>(), result["num_threads"].as<int>());
    simulation.run(result["flock_size"].as<int>());

    return EXIT_SUCCESS;
}
