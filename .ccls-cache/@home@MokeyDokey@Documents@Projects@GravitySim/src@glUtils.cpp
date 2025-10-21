#include <glUtils.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

std::string loadFile(const char* path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error(std::string("Failed to open: ") + path);
    }
    std::stringstream buf;
    buf << file.rdbuf();
    return buf.str();
}

void framebuffer_size_callback(GLFWwindow*, int w, int h){
    glViewport(0, 0, w, h);
}

GLuint compile(GLenum type, const char* src){
    GLuint sh = glCreateShader(type);
    glShaderSource(sh, 1, &src, nullptr);
    glCompileShader(sh);
    GLint ok = 0;
    glGetShaderiv(sh, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        char log[4096];
        glGetShaderInfoLog(sh, 4096, nullptr, log);
        std::cerr << "Shader compile error:\n" << log << "\n";
    }
    return sh;
}

GLuint link(GLuint a, GLuint b, GLuint c){
    GLuint p = glCreateProgram();
    glAttachShader(p, a);
    glAttachShader(p, b);
    if(c) glAttachShader(p, c);
    glLinkProgram(p);
    glDetachShader(p, a);
    glDetachShader(p, b);
    if(c) glDetachShader(p, c);
    GLint ok=0; glGetProgramiv(p, GL_LINK_STATUS, &ok);
    if(!ok){
        char log[4096];
        glGetProgramInfoLog(p, 4096, nullptr, log);
        std::cerr << "Link error:\n" << log << "\n";
    }
    return p;
}

void makePerspective(float* m, float fovYRadians, float aspect, float znear, float zfar){
    float f = 1.0f / std::tan(fovYRadians * 0.5f);
    for(int i=0;i<16;++i) m[i]=0.0f;
    m[0]  = f / aspect;
    m[5]  = f;
    m[10] = (zfar + znear) / (znear - zfar);
    m[11] = -1.0f;
    m[14] = (2.0f * zfar * znear) / (znear - zfar);
}

void makeViewTranslateZ(float* m, float camDist){
    for(int i=0;i<16;++i) m[i]=0.0f;
    m[0]=1.0f; m[5]=1.0f; m[10]=1.0f; m[15]=1.0f;
    m[14] = -camDist;
}

float frand(){ 
    return std::rand() / float(RAND_MAX); 
}
