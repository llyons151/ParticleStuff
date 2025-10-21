#pragma once
#include <cstdlib>

class Particle{
    private:
    public:
        Particle();
        Particle(float r, float g, float b); 
        float m_x, m_y, m_z;
        float m_r, m_g, m_b;
        float m_mass;
};
