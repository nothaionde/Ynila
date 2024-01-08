#ifndef GLFWWINDOW_H_
#define GLFWWINDOW_H_

#include <string>

#include "glad/gl.h"
// GLFW (include after glad)
#include "GLFW/glfw3.h"

#include "src/Engine/Core/Window.h"

// Scene
#include "src/Engine/Scene/Scene.h"

namespace Ynila {
    class WinWindow : public Window
    {
    public:
        WinWindow();

        ~WinWindow() override = default;

        void OnUpdate() override;

        bool ShouldClose() override;

        void Terminate() override;

        void Initialize() override;

        void *GetNativeWindow() const
        {
            return m_Window;
        };

        uint32_t GetWidth() const override
        {
            return m_Width;
        }

        uint32_t GetHeight() const override
        {
            return m_Height;
        }

    private:
        GLFWwindow *m_Window;
        Scene *m_Scene;
        int m_Width;
        int m_Height;
        std::string m_Title;
    };
} // namespace Ynila

#endif // !GLFWWINDOW_H_
