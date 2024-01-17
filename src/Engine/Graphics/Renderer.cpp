#include "Renderer.h"

namespace Ynila {

    GLuint Renderer::VBO = 0;
    GLuint Renderer::VAO = 0;
    std::unique_ptr<Shader> Renderer::shader = nullptr;
    glm::vec3 Renderer::pos = {0.0f, 0.0f, 0.0f};
    glm::vec4 Renderer::color = {0.0f, 0.0f, 0.0f, 0.0f};

    const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        uniform mat4 model;
        uniform mat4 view;
        uniform mat4 projection;
        out vec4 vertexColor;
        uniform vec4 color;
        void main()
        {
            gl_Position = projection * view * model * vec4(aPos, 1.0);
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

    void Renderer::BeginScene(const Camera camera)
    {
        shader->Bind();
        shader->UploadUniformMat4("view", camera.GetViewMatrix());
        shader->UploadUniformMat4("projection", camera.GetProjectionMatrix());
    }

    void Renderer::EndScene()
    {
        DrawTriangle(pos, color);
    }

    void Renderer::DrawTriangle(const glm::vec3 &position, const glm::vec4 &color)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, position);

        glBindVertexArray(VAO);
        shader->Bind();
        shader->UploadUniformMat4("model", model);
        shader->UploadUniformFloat4("color", color);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        shader->Unbind();
    }
} // namespace Ynila