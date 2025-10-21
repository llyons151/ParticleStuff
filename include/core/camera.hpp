#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <math.h>

class Camera{
    private:
        glm::vec3 m_cameraPos;
        glm::vec3 m_cameraTarget;
        glm::vec3 m_cameraDirection;
        glm::vec3 m_cameraRight;
        glm::vec3 m_cameraUp;
        glm::vec3 m_up;
        glm::mat4 m_cameraView;
        float m_radius;
        int m_height;
        int m_width;
        const float m_FOV = 50.0f;

    public:
        glm::mat4 model;
        glm::mat4 view;
        glm::mat4 proj;
        glm::vec3 eye;

    public:
        void setCameraPos(glm::vec3 vector);
        glm::vec3 getCameraPos();
        glm::mat4 getCameraView();
        Camera(int width, int height);
        void circle();
        void update();
};
