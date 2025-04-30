// ClothApp.h

#pragma once
#include <SFML/Graphics.hpp>
#include "../core/Solver.h"
#include "../core/Integrator.h"

namespace cloth
{

    constexpr float PARTICLE_RADIUS = 5.f; // Particle radius
    constexpr float PARTICLE_MASS = 1.f; // Particle mass
    constexpr float PARTICLE_DISTANCE = 20.f; // Distance between particles

    constexpr int ROWS = 10; // Number of rows of particles
    constexpr int COLS = 10; // Number of columns of particles

    class ClothApp
    {
        sf::RenderWindow window;
        core::Solver<core::EulerIntegrator> solver;

    public:
        ClothApp();
        ~ClothApp() = default;
        
        void init();
        void run();
    };
}