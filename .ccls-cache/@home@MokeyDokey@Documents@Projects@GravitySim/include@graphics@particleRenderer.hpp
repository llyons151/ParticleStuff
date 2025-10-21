#pragma once
#include <glad/glad.h>
#include "graphics/particle.hpp"
#include <cstddef> 

class ParticleRenderer{
    public:
        ParticleRenderer(const Particle* particles, int numParticles);
        //~ParticleRenderer();
        void drawParticles() const;

    private:
        unsigned int m_VBO;
        unsigned int m_VAO;
        int m_numParticles;
};
