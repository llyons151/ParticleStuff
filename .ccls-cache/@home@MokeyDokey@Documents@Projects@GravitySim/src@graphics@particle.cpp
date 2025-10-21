#include "graphics/particle.hpp"

Particle::Particle() {
    m_x = (std::rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    m_y = (std::rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    m_z = (std::rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    m_r = 1.0f;
    m_g = 1.0f;
    m_b = 1.0f;
    m_mass = 1.0f;
}

Particle::Particle(float r, float g, float b) : m_r(r), m_g(g), m_b(b) {
    m_mass = 1.0f;
};
