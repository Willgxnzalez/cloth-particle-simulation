// Solver.h

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Integrator.h"

namespace core {
    template <typename IntegratorT>
    class Solver {
        std::vector<Particle> particles;
        IntegratorT integrator;
        float dt;

        static constexpr sf::Vector2f GRAVITY {0.0, 9.81f};

    public:
        Solver(float timeStep = 1/60.f) : dt(timeStep) {}
        ~Solver() = default;

        void addParticle(const Particle &particle) { particles.push_back(particle); }
        std::vector<Particle> & getParticles() { return particles; }



        void step() {
            // Apply forces to particles
            for (auto &particle : particles) 
                particle.force = GRAVITY * particle.mass;
            
            // Integrate particle positions and velocities
            // integrator.step(particles, dt);

            // Apply constraints
            // for (auto &constraint : constraints) {
            //     constraint.apply(particles);
        }
    };
}