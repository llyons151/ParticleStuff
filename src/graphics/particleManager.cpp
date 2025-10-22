#include "graphics/particleManager.hpp"
#include <cmath>
#include <GLFW/glfw3.h> 

ParticleManager::ParticleManager() {
}

void ParticleManager::wave1(std::vector<Particle>& particles) {
    float t = glfwGetTime();
    for (auto& p : particles) {
        p.m_x += sin(p.m_y * 2.0f + t) * 0.02f;
        p.m_y += cos(p.m_x * 2.0f - t) * 0.02f;
        p.m_z += cos(p.m_z * 2.0f - t) * 0.02f;
    }
}

void ParticleManager::wave2(std::vector<Particle>& particles) {
    float t = glfwGetTime() * 2.0f; 
    for (auto& p : particles) {
        float swirl = sin(p.m_x * 0.8f + t) * cos(p.m_y * 0.6f - t * 0.5f);
        float pulse = sin(p.m_z * 0.4f + t * 1.5f) * 0.5f;

        p.m_x += 0.02f * sin(p.m_y * 2.0f + t) + 0.01f * swirl;
        p.m_y += 0.02f * cos(p.m_x * 2.5f - t) + 0.01f * pulse;
        p.m_z += 0.02f * sin(p.m_x * 1.5f + p.m_y * 1.2f - t) + 0.01f * swirl;
    }
}

void ParticleManager::wave3(std::vector<Particle>& particles) {
    float t = glfwGetTime() * 1.8f;  
    for (auto& p : particles) {
        float r = sqrt(p.m_x * p.m_x + p.m_y * p.m_y + p.m_z * p.m_z);

        float angle = t + r * 2.0f;
        float vortexX = sin(angle) * 0.02f;
        float vortexY = cos(angle) * 0.02f;

        float pulse = sin(t * 1.5f + r * 3.0f) * 0.015f;

        p.m_x += vortexX;
        p.m_y += vortexY;
        p.m_z += sin(r * 1.5f - t) * 0.02f + pulse * 0.5f;
    }
}

void ParticleManager::wave4(std::vector<Particle>& particles){
    static float prev = glfwGetTime();
    float now = glfwGetTime();
    float dt  = std::min(0.033f, now - prev); 
    prev = now;

    constexpr int   N   = 5;      
    const float     A   = 0.020f;  
    const float     kx  = 1.35f, ky = 1.18f, kz = 1.07f; 
    const float     wx  = 0.80f, wy = 0.90f, wz = 1.00f;  
    const float     drift = 0.15f; 
    const float     tilt  = 0.28f;
    const float     bound = 0.10f; 
    const float     step  = (dt * 60.0f) * A;

    const float GOLD = 3.14159265358979323846f * (3.0f - std::sqrt(5.0f)); 

    static constexpr float wX[N] = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    static constexpr float wY[N] = {0.90f, 0.94f, 0.98f, 1.02f, 1.06f};
    static constexpr float wZ[N] = {1.28f, 1.22f, 1.16f, 1.10f, 1.04f};
    static constexpr float offX[N] = {
        1.3f*0, 1.3f*1, 1.3f*2, 1.3f*3, 1.3f*4
    };
    static constexpr float offY[N] = {
       -0.7f*0,-0.7f*1,-0.7f*2,-0.7f*3,-0.7f*4
    };
    static constexpr float offZ[N] = {
        0.2f*0, 0.2f*1, 0.2f*2, 0.2f*3, 0.2f*4
    };

    struct Dir { float x,y,z; };
    Dir d[N];
    float cX_y[N], cX_z[N], cY_x[N], cY_z[N], cZ_x[N], cZ_y[N];

    for (int i = 0; i < N; ++i) {
        float a  = i * GOLD + drift * now;
        float ca = std::cos(a), sa = std::sin(a);
        float zz = tilt * std::sin(0.7f * a);

        float invLen = 1.0f / std::sqrt(ca*ca + sa*sa + zz*zz);
        d[i] = { ca * invLen, sa * invLen, zz * invLen };

        cX_y[i] = wX[i] * kx * d[i].y; 
        cX_z[i] = wX[i] * kx * d[i].z;
        cY_x[i] = wY[i] * ky * d[i].x; 
        cY_z[i] = wY[i] * ky * d[i].z; 
        cZ_x[i] = wZ[i] * kz * d[i].x; 
        cZ_y[i] = wZ[i] * kz * d[i].y; 
    }

    for (std::int64_t idx = 0; idx < (std::int64_t)particles.size(); ++idx) {
        auto& p = particles[(size_t)idx];
        float x = p.m_x, y = p.m_y, z = p.m_z;

        float vx = 0.0f, vy = 0.0f, vz = 0.0f;

        for (int i = 0; i < N; ++i) {
            float base = d[i].x * x + d[i].y * y + d[i].z * z;  

            float phx = kx * base - wx * now + offX[i];
            float phy = ky * base - wy * now + offY[i];
            float phz = kz * base - wz * now + offZ[i];

            float cx = std::cos(phx);
            float cy = std::cos(phy);
            float cz = std::cos(phz);

            vx += cZ_y[i] * cz - cY_z[i] * cy;
            vy += cX_z[i] * cx - cZ_x[i] * cz;
            vz += cY_x[i] * cy - cX_y[i] * cx;
        }

        float r2   = x*x + y*y + z*z;
        float conf = 1.0f / (1.0f + bound * r2);

        p.m_x += step * vx * conf;
        p.m_y += step * vy * conf;
        p.m_z += step * vz * conf;
    }
}
    void ParticleManager::wave5(std::vector<Particle>& particles) {
        float t = glfwGetTime();
        for (auto& p : particles) {
            float r = sqrt(p.m_x * p.m_x + p.m_y * p.m_y + p.m_z * p.m_z);
            float scale = sin(t * 2.0f + r * 5.0f) * 0.1f;
            float twist = cos(r * 3.0f - t * 4.0f) * 0.05f;

            p.m_x += p.m_x * scale + sin(p.m_y * 2.0f + t) * twist;
            p.m_y += p.m_y * scale + cos(p.m_x * 2.0f - t) * twist;
            p.m_z += p.m_z * scale + sin(p.m_z * 2.0f + t * 0.5f) * twist;
        }
    }
