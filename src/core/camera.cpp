#include "core/camera.hpp"

Camera::Camera(int width, int height){
    m_width = width;
    m_height = height;
    m_radius = 10.0f;
    m_cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    m_cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    m_cameraDirection = glm::normalize(m_cameraPos - m_cameraTarget);
    m_up = glm::vec3(0.0f, 1.0f, 0.0f);
    m_cameraRight = glm::normalize(glm::cross(m_up, m_cameraDirection));
    m_cameraUp = glm::cross(m_cameraDirection, m_cameraRight);
    m_cameraView = glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f),
                         glm::vec3(0.0f, 0.0f, 0.0f),
                         glm::vec3(0.0f, 1.0f, 0.0f));
};

void Camera::setCameraPos(glm::vec3 vector){ m_cameraPos = vector; };
glm::vec3 Camera::getCameraPos(){ return m_cameraPos; };
glm::mat4 Camera::getCameraView(){ return m_cameraView; };

void Camera::circle(){
    float camX = sin(glfwGetTime()) * m_radius -10;
    float camZ = cos(glfwGetTime()) * m_radius -10;
    m_cameraView = glm::lookAt(glm::vec3(camX, 0.0f, camZ),
                         glm::vec3(0.0f, 0.0f, 0.0f),
                         glm::vec3(0.0f, 1.0f, 0.0f));
    m_cameraPos = glm::vec3(camX, 0.0f, camZ);
};

void Camera::update(){
    model = glm::mat4(1.0f);
    view  = getCameraView();
    proj  = glm::perspective(glm::radians(m_FOV), m_width/(float)m_height, 0.1f, 100.0f);
    eye   = getCameraPos();
};
