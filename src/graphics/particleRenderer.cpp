#include "graphics/particleRenderer.hpp"

struct GPUVert{
    float m_x, m_y, m_z;
    float m_r, m_g, m_b;
};

ParticleRenderer::ParticleRenderer(const Particle* particles, int numParticles){
    m_numParticles = numParticles;

    // Genderate buffer IDs and bind it
    glGenBuffers(1, &m_VBO);
    glGenVertexArrays(1, &m_VAO);
    // Bind buffers
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    // Copy data into the defined buffer
    glBufferData(GL_ARRAY_BUFFER, m_numParticles * sizeof(GPUVert), particles, GL_DYNAMIC_DRAW);

    // Tells OpenGL how to interprate vertex data
    glEnableVertexAttribArray(0);
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof(GPUVert), (void*)offsetof(Particle, m_x));

    // Unbind VAO and VBO now that they are set up
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
};

void ParticleRenderer::drawParticles() const{
    glBindVertexArray(m_VAO);
    glDrawArrays(GL_POINTS, 0, m_numParticles);
};

void ParticleRenderer::updateBuffers(const std::vector<Particle>& particles){
    std::vector<GPUVert> particleVerts; 
    particleVerts.reserve(particles.size());

    for(const auto& p : particles){
        // Upload particle data to format the GPU understands
        particleVerts.push_back({p.m_x, p.m_y, p.m_z, p.m_r, p.m_g, p.m_b});
    };

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, particleVerts.size() * sizeof(GPUVert), particleVerts.data(), GL_DYNAMIC_DRAW); 
};
