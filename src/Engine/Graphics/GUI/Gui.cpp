#include "Gui.h"
#include "src/Engine/Core/Application.h"
#include "src/Engine/Core/Logger.h"

// Temporary
#include "src/Engine/Graphics/Renderer.h"
#include "src/Engine/Scene/Scene.h"


#include "glad/gl.h"
// GLFW (include after glad)
#include "GLFW/glfw3.h"

namespace Ynila {

    void TriangleTest()
    {
        ImGui::Begin("Triangle Test");

        static float slider1 = 1.0f;
        static float slider2 = 0.0f;
        static float slider3 = 0.0f;
        static float slider4 = 1.0f;
        static float slider5 = 0.0f;
        static float slider6 = 0.0f;
        static float slider7 = -1.0f;

        ImGui::SliderFloat("Red Color", &slider1, 0.0f, 1.0f);
        ImGui::SliderFloat("Green Color", &slider2, 0.0f, 1.0f);
        ImGui::SliderFloat("Blue Color", &slider3, 0.0f, 1.0f);
        ImGui::SliderFloat("Alpha", &slider4, 0.0f, 1.0f);
        ImGui::NewLine();
        ImGui::SliderFloat("Pos x", &slider5, -1.0f, 1.0f);
        ImGui::SliderFloat("Pos y", &slider6, -1.0f, 1.0f);
        ImGui::SliderFloat("Pos z", &slider7, -1.0f, 1.0f);

        Renderer::color = { slider1, slider2, slider3, slider4 };
        Renderer::pos = { slider5, slider6, slider7 };

        ImGui::End();
    }

    void CameraTest()
    {
        ImGui::Begin("Camera Test");

        static float distance = 0.2f;

        if (ImGui::Button("Up"))
        {
            Scene::GetInstance()->m_Camera->MoveUp(distance);
        }
        if (ImGui::Button("Down"))
        {
            Scene::GetInstance()->m_Camera->MoveDown(distance);
        }
        if (ImGui::Button("Left"))
        {
            Scene::GetInstance()->m_Camera->MoveLeft(distance);
        }
        if (ImGui::Button("Right"))
        {
            Scene::GetInstance()->m_Camera->MoveRight(-distance);
        }
        if (ImGui::Button("Forward"))
        {
            Scene::GetInstance()->m_Camera->MoveForward(distance);
        }
        if (ImGui::Button("Backward"))
        {
            Scene::GetInstance()->m_Camera->MoveBackward(distance);
        }
        if (ImGui::Button("Rotate"))
        {
            Scene::GetInstance()->m_Camera->Rotate(45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
        }

        ImGui::End();
    }

    Gui::Gui()
    {
    }

    void Gui::Initialize()
    {
        const char *glsl_version = "#version 410";
        auto application = Application::GetInstance();
        GLFWwindow *window = static_cast<GLFWwindow *>(application.GetInstance().GetWindow().GetNativeWindow());
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        (void) io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);
    }

    void Gui::Update()
    {
        ImGuiIO &io = ImGui::GetIO();
        Application &app = Application::GetInstance();
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        TriangleTest();
		CameraTest();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
} // namespace Ynila
