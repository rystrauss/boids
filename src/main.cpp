#include "Simulation.h"
#include "cxxopts.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    cxxopts::Options options("Boids", "Runs a simulation of Craig Reynolds' boids.");
    options.add_options()
            ("w,width", "Width of the window.",
             cxxopts::value<int>()->default_value(std::to_string(Simulation::DEFAULT_WINDOW_WIDTH)))
            ("h,height", "Height of the window.",
             cxxopts::value<int>()->default_value(std::to_string(Simulation::DEFAULT_WINDOW_HEIGHT)))
            ("max_speed", "Maximum speed of a boid.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_MAX_SPEED)))
            ("max_force", "Maximum force that can be applied to a boid.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_MAX_FORCE)))
            ("n,flock_size", "Initial size of the flock.",
             cxxopts::value<int>()->default_value(std::to_string(Simulation::DEFAULT_FLOCK_SIZE)))
            ("alignment_weight", "Weight applied to the alignment rule.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_ALIGNMENT_WEIGHT)))
            ("cohesion_weight", "Weight applied to the cohesion rule.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_COHESION_WEIGHT)))
            ("separation_weight", "Weight applied to the separation rule.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_SEPARATION_WEIGHT)))
            ("acceleration_scale", "Scaling factor applied to boids' acceleration.",
             cxxopts::value<float>()->default_value(std::to_string(Simulation::DEFAULT_ACCELERATION_SCALE)));
    auto result = options.parse(argc, argv);

    std::cout << result["width"].as<int>() << std::endl;

    Simulation simulation(result["width"].as<int>(), result["height"].as<int>(), result["max_speed"].as<float>(),
                          result["max_force"].as<float>(), result["alignment_weight"].as<float>(),
                          result["cohesion_weight"].as<float>(), result["separation_weight"].as<float>(),
                          result["acceleration_scale"].as<float>());
    simulation.run(result["flock_size"].as<int>());

    return EXIT_SUCCESS;
}
