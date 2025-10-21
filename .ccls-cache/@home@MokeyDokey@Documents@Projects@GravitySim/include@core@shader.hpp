#pragma once
#include <glad/glad.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

class Shader{
    private:
        unsigned int m_shaderProgram;

    private:
        std::string loadSource(const std::string& path);

    public:
        Shader(const std::string& vertPath, const std::string& fragPath);
        void useShaderProgram() const;
        unsigned int getShaderProgram();

};
