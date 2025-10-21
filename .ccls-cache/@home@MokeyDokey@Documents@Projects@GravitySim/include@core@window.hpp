#pragma once
#include <string>
struct GLFWwindow;

class Window{
    private:
        int m_windowWidth; 
        int m_windowHeight; 
        GLFWwindow* m_window;

    public:
        bool createWindow(int width, int height, std::string name);
        bool shouldClose() const;
        void makeCurrent() const;
        void setBackgroundColor() const;
        void pollEvents() const;
        void swapBuffers() const;
        void shutDown();
};
