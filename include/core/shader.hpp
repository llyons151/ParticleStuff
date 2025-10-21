#pragma once
#include <glm/gtc/type_ptr.hpp>    
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
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
        GLint uModel, uView, uProj, uEye;
        Shader(const std::string& vertPath, const std::string& fragPath);
        void useShaderProgram() const;
        unsigned int getShaderProgram();
        void cacheCommonUniforms();
        void setMat4(GLint loc, const glm::mat4& m) const;
        void setVec3(GLint loc, const glm::vec3& v) const;
        void uploadToShader(glm::mat4 model,
                            glm::mat4 view,
                            glm::mat4 proj,
                            glm::vec3 eye);

};
