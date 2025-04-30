// ClothApp.cpp

#include "ClothApp.h"

namespace cloth
{
    ClothApp::ClothApp() 
        : window(sf::VideoMode({800, 600}), "Cloth Simulation"), 
          solver(1.f / 60.f) // time step of 1/60 seconds
    {
    }

    void ClothApp::init() {
        static const float OFFSETX = (window.getSize().x - (COLS * PARTICLE_DISTANCE)) / 2.f;
        static const float OFFSETY = (window.getSize().y - (ROWS * PARTICLE_DISTANCE)) / 2.f;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
            core::Particle particle;
            particle.position = {OFFSETX + j * PARTICLE_DISTANCE, OFFSETY + i * PARTICLE_DISTANCE};
            particle.previousPosition = particle.position;
            particle.velocity = {0.f, 0.f};
            particle.force = {0.f, 0.f};
            particle.mass = 1.f;
            solver.addParticle(particle);
            }
        }
    }

    void ClothApp::run() {
        while (window.isOpen()) {
            while (const std::optional<sf::Event> event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
                if (event->is<sf::Event::KeyPressed>()) {
                    if (const auto *keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                        if (keyEvent->code == sf::Keyboard::Key::Escape) {
                            window.close();
                        }
                    }
                }
            }

            solver.step(); // Update the simulation

            window.clear(sf::Color::Black);

            for (const auto &particle: solver.getParticles()) {
                sf::CircleShape shape(5.f);
                shape.setPosition(particle.position);
                shape.setFillColor(sf::Color::White);
                window.draw(shape);
            }

            window.display();
        }
    }
}