#pragma once
#include "graphics/particle.hpp"
#include <GLFW/glfw3.h>
#include <math.h>
#include <cmath>
#include <cstdint>     
#include <vector>

class ParticleManager{
    private:
    public:
        ParticleManager();
        void wave1(std::vector<Particle>& particles);
        void wave2(std::vector<Particle>& particles);
        void wave3(std::vector<Particle>& particles);
        void wave4(std::vector<Particle>& particles);
        void wave5(std::vector<Particle>& particles);
};
