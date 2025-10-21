#include "graphics/particleRenderer.hpp"
#include <vector>

ParticleRenderer::ParticleRenderer(const Particle* particles, int numParticles){
    m_numParticles = numParticles;

    // Genderate buffer IDs and bind it
    glGenBuffers(1, &m_VBO);
    glGenVertexArrays(1, &m_VAO);
    // Bind buffers
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    // Copy data into the defined buffer
    glBufferData(GL_ARRAY_BUFFER, m_numParticles * sizeof(Particle), particles, GL_DYNAMIC_DRAW);

    // Tells OpenGL how to interprate vertex data
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
            0, 3, GL_FLOAT, GL_FALSE,
            sizeof(Particle),
            (void*)offsetof(Particle, m_x)
            );

    // Unbind VAO and VBO now that they are set up
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
};

void ParticleRenderer::drawParticles() const{
    glBindVertexArray(m_VAO);
    glDrawArrays(GL_POINTS, 0, m_numParticles);
    glBindVertexArray(0);
};
