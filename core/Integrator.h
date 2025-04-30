// Integrator.h

#pragma once
#include <SFML/Graphics.hpp>

namespace core 
{
    struct Particle {
        sf::Vector2f position;
        sf::Vector2f previousPosition; // For Verlet integration
        sf::Vector2f velocity; // For Euler integration
        sf::Vector2f force;
        float mass;
    };

    class Integrator {
        public:
            Integrator() = default;
            ~Integrator() = default;

            virtual void step(std::vector<Particle> &particles, float timeStep) = 0;
    };

    class EulerIntegrator : public Integrator {
        public:
            void step(std::vector<Particle> &particles, float timeStep) override {
                for (auto &particle : particles) {
                    particle.velocity += (particle.force / particle.mass) * timeStep;
                    particle.position += particle.velocity * timeStep;
                }
            }
    };
}