#include "Renderer.h"
#include "src/Engine/Core/Logger.h"
#include "src/Engine/Graphics/Shader.h"

namespace Ynila {

    GLuint VBO, VAO;
    int shaderProgram;
    std::unique_ptr<Shader> shader;

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
        shader = std::make_unique<Shader>("Test", vertexShaderSource, fragmentShaderSource);
    }

    void Renderer::DrawTriangle(const glm::vec3 &position, const glm::vec4 &color)
    {
        glBindVertexArray(VAO);
        shader->Bind();
        shader->UploadUniformFloat4("color", color);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        shader->Unbind();
    }
} // namespace Ynila