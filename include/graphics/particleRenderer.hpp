#pragma once
#include <glad/glad.h>
#include "graphics/particle.hpp"
#include <cstddef> 
#include <vector>

class ParticleRenderer{
    public:
        ParticleRenderer(const Particle* particles, int numParticles);
        void drawParticles() const;
        void updateBuffers(const std::vector<Particle>& particles);  

    private:
        unsigned int m_VBO;
        unsigned int m_VAO;
        int m_numParticles;
};
