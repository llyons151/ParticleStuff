#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

struct vec3 {
    float x, y, z;
};

class Line {
    private:
        GLuint shaderProgram;
        unsigned int VBO, VAO;
        std::vector<float> vertices;
        vec3 startPoint;
        vec3 endPoint;
        vec3 lineColor;

        void setupGL() {
            glGenVertexArrays(1, &VAO);
            glGenBuffers(1, &VBO);

            glBindVertexArray(VAO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);

            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
        }

    public:
        Line(int shaderProgram, const std::vector<float>& vertices, vec3 startPoint, vec3 endPoint)
            : shaderProgram(shaderProgram),
            vertices(vertices),
            startPoint(startPoint),
            endPoint(endPoint),
            lineColor({1.0f, 1.0f, 1.0f}) {
                setupGL();
            }

        ~Line() {
            glDeleteBuffers(1, &VBO);
            glDeleteVertexArrays(1, &VAO);
        }

        void draw() {
            glUseProgram(shaderProgram);
            glBindVertexArray(VAO);
            glDrawArrays(GL_LINES, 0, vertices.size() / 3);
            glBindVertexArray(0);
        }
};

