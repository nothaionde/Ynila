#include "Renderer.h"
#include "src/Engine/Core/Logger.h"

namespace Ynila {

    GLuint VBO, VAO;
    int shaderProgram;

    const char* vertexShaderSource = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    out vec4 vertexColor;
    uniform vec4 color;
    void main()
    {
        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
        vertexColor = color;
    }
)";

    const char* fragmentShaderSource = R"(
    #version 330 core
    in vec4 vertexColor;
    out vec4 FragColor;
    void main()
    {
        FragColor = vertexColor;
    }  
)";

    void Renderer::Initialize()
    {
        float vertices[] = {
                -0.5f, -0.5f, 0.0f,
                0.5f, -0.5f, 0.0f,
                0.0f, 0.5f, 0.0f
        };

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(vertexShader);

        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, sizeof(infoLog), nullptr, infoLog);
            YNILA_CORE_LOGGER_ERROR("Vertex shader compilation failed: {}", infoLog);
        }

        int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, sizeof(infoLog), nullptr, infoLog);
            YNILA_CORE_LOGGER_ERROR("Fragment shader compilation failed: {}", infoLog);
        }

        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, sizeof(infoLog), nullptr, infoLog);
            YNILA_CORE_LOGGER_ERROR("Shader linking failed: {}", infoLog);
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void Renderer::DrawTriangle(const glm::vec3 &position, const glm::vec4 &color)
    {
        glBindVertexArray(VAO);

        glUseProgram(shaderProgram);

        GLuint colorLocation = glGetUniformLocation(shaderProgram, "color");

        glUniform4f(colorLocation, color.x, color.y, color.z, color.w);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(0);
    }
} // namespace Ynila