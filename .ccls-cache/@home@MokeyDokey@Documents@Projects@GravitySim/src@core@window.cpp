#include "core/window.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

bool Window::createWindow(int width, int height, std::string name){
    // Set member variables
    m_windowWidth = width;
    m_windowHeight = height;

    // Creating the window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, "Gravity Sim", NULL, NULL);
    if(m_window == NULL) {
        std::cout << "Error init window" << std::endl;
        glfwTerminate();
        return false;
    }

    // Tells OpenGL to use the window as context
    glfwMakeContextCurrent(m_window);

    // Make sure glad loads
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Error init glad" << std::endl;
        return -1;
    };

    // Sets view port
    glViewport(0, 0, m_windowWidth, m_windowHeight);

    return true;
};

bool Window::shouldClose() const {
    return glfwWindowShouldClose(m_window);
};

void Window::pollEvents() const {
    // Checks for triggered events like keyboard and mouse
    glfwPollEvents();
};

void Window::setBackgroundColor() const {
    glClearColor(0.05f, 0.07f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
};

void Window::swapBuffers() const {
    // Swaps buffers to prevent flickering issues 
    glfwSwapBuffers(m_window);
};

void Window::shutDown(){
    if(m_window){
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    };
    glfwTerminate();
};
