#include "Gui.h"
#include "src/Engine/Core/Application.h"
#include "src/Engine/Core/Logger.h"


#include "glad/gl.h"
// GLFW (include after glad)
#include "GLFW/glfw3.h"

namespace Ynila {
    Gui::Gui()
    {
    }

    void Gui::Initialize()
    {
        const char* glsl_version = "#version 410";
        auto application = Application::GetInstance();
        GLFWwindow *window = static_cast<GLFWwindow *>(application.GetInstance().GetWindow().GetNativeWindow());
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);
    }

    void Gui::Update()
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::GetInstance();
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
}
