#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "core/window.hpp"
#include "core/shader.hpp"
#include "graphics/particle.hpp"
#include "graphics/particleRenderer.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[]){

    Window window;
    if(!window.createWindow(1600, 1200, "Gravity Sim")) return -1;

    // Create and use shaders
    Shader shader("../shaders/basic.vert", "../shaders/basic.frag");
    shader.useShaderProgram();

    // Create the particles
    int numParticles = 100000;

    // Check for arguments
    if(argc > 1){
        std::cout << "Making " << argv[1] << " Particles" << std::endl;
        numParticles = std::stoi(argv[1]);
    };

    Particle particles[numParticles];

    ParticleRenderer particleRenderer(particles, numParticles);

    // Main loop
    while(!window.shouldClose()){
        window.setBackgroundColor();
        
        particleRenderer.drawParticles();

        window.swapBuffers();
        window.pollEvents();
    };
    window.shutDown();
    return 0;
};
