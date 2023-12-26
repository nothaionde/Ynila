#include "Application.h"

namespace Ynila {
    Application *Application::s_Instance = nullptr;

    Application::Application()
    {
        s_Instance = this;
        m_Window = Window::CreateWindow();
        m_Window->Initialize();
    }

    void Application::Run()
    {
        while (!m_Window->ShouldClose()) {
            m_Window->OnUpdate();
        }
        m_Window->Terminate();
    }
}
