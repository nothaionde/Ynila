#include "Gui.h"
#include "src/Engine/Core/Application.h"
#include "src/Engine/Core/Logger.h"

// Temporary
#include "src/Engine/Scene/Scene.h"


#include "glad/gl.h"
// GLFW (include after glad)
#include "GLFW/glfw3.h"

namespace Ynila {

    Scene *m_Scene = nullptr;

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

        ImGui::Begin("Triangle color");

        static float slider1 = 0.0f;
        static float slider2 = 0.0f;
        static float slider3 = 0.0f;
        static float slider4 = 1.0f;

        ImGui::SliderFloat("Red Color:", &slider1, 0.0f, 1.0f);
        ImGui::SliderFloat("Green Color:", &slider2, 0.0f, 1.0f);
        ImGui::SliderFloat("Blue Color:", &slider3, 0.0f, 1.0f);
        ImGui::SliderFloat("Alpha:", &slider4, 0.0f, 1.0f);

        m_Scene = Scene::GetInstance();
        m_Scene->color = {slider1, slider2, slider3, slider4};

        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
} // namespace Ynila
