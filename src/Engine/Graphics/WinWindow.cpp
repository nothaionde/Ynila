#include "WinWindow.h"
#include "src/Engine/Core/Logger.h"

namespace Ynila {
    WinWindow::WinWindow()
    {
        m_Height = 720;
        m_Width = 1280;
        m_Title = "Ynila";
    }

    void WinWindow::OnUpdate()
    {
        glClearColor(0.1f, 0.1f, 0.1f, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        m_Scene->OnUpdate();
        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }

    bool WinWindow::ShouldClose()
    {
        return glfwWindowShouldClose(m_Window);
    }

    void WinWindow::Terminate()
    {
        glfwTerminate();
    }

    void WinWindow::Initialize()
    {
        if (!glfwInit()) {
            YNILA_CORE_LOGGER_CRITICAL("GLFW initialization failed!");
        }
        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);

        if (!m_Window) {
            YNILA_CORE_LOGGER_CRITICAL("GLFW window creation failed!");
            glfwTerminate();
        }
        glfwMakeContextCurrent(m_Window);

        int version = gladLoadGL(glfwGetProcAddress);
        if (version == 0) {
            YNILA_CORE_LOGGER_CRITICAL("Failed to initialize OpenGL context!");
        }
        m_Scene = new Scene();
    }
} // namespace Ynila
