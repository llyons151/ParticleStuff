#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "core/window.hpp"
#include "core/camera.hpp"
#include "core/shader.hpp"
#include "graphics/particle.hpp"
#include "graphics/particleRenderer.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

int main(int argc, char* argv[]){

    Window window;
    const int WINDOW_WIDTH = 1200;
    const int WINDOW_HEIGHT = 800;
    if(!window.createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Gravity Sim")) return -1;

    Camera camera(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Create and use shaders
    Shader shader("../shaders/basic.vert", "../shaders/basic.frag");
    shader.useShaderProgram();
    shader.cacheCommonUniforms();

    // Create the particles
    int numParticles = 100000;

    // Check for arguments
    if(argc > 1){
        std::cout << "Making " << argv[1] << " Particles" << std::endl;
        numParticles = std::stoi(argv[1]);
    };

    std::vector<Particle> particles(numParticles);

    ParticleRenderer particleRenderer(particles.data(), numParticles);

    // Main loop
    while(!window.shouldClose()){
        window.setBackgroundColor();

        for (auto& p : particles) {
            p.m_x += sin(p.m_y * 2.0f + glfwGetTime()) * 0.02f;
            p.m_y += cos(p.m_x * 2.0f - glfwGetTime()) * 0.02f;
            p.m_z += cos(p.m_z * 2.0f - glfwGetTime()) * 0.02f;
        }

        particleRenderer.updateBuffers(particles);
        particleRenderer.drawParticles();

        camera.update();

        // Upload camera info to shaders
        shader.uploadToShader(camera.model, camera.view,
                              camera.proj,  camera.eye);

        // Camera movement
        camera.zoomOut();

        window.swapBuffers();
        window.pollEvents();
    };
    window.shutDown();
    return 0;
};
