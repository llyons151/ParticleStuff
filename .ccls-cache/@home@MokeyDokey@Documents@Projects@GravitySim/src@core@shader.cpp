#include "core/shader.hpp"
#include <string>
#include <iostream>
#include <fstream>

std::string Shader::loadSource(const std::string& path){
    std::ifstream file(path);
    if(!file.is_open()){
        std::cout << "Could not open shader path:" << path << std::endl;
        return "";
    };

    std::stringstream buffer;
    // Read the entire file's content into the stringstream buffer
    buffer << file.rdbuf();

    file.close();

    return buffer.str();
};

Shader::Shader(const std::string& vertPath, const std::string& fragPath){
    // Load shader from source and convert to char
    std::string source = loadSource(vertPath);
    const char* vertexShaderSource = source.c_str();

    // Create shader object
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // Atach and compile shader
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Load shader from source and convert to char
    source = loadSource(fragPath);
    const char* fragmentShaderSource = source.c_str();

    // Create shader object
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Atach and compile shader
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Create shader program object
    m_shaderProgram = glCreateProgram();

    // Attach and link compiled shaders to the shader program object
    glAttachShader(m_shaderProgram, vertexShader);
    glAttachShader(m_shaderProgram, fragmentShader);
    glLinkProgram(m_shaderProgram);

    // Delete the shaders now that they are not needed
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
};

void Shader::useShaderProgram() const {
    glUseProgram(m_shaderProgram);
};
