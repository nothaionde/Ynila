#include "Window.h"
#include "src/Engine/Core/Logger.h"
#include "src/Engine/Graphics/WinWindow.h"

namespace Ynila {

	// TODO: After implementing more than one Rendering Api change it
    RenderingApi Window::m_renderingApi = RenderingApi::OpenGL;

    Window *Window::CreateWindow()
    {
        switch (m_renderingApi)
        {
            case RenderingApi::OpenGL:
                return new WinWindow();
            case RenderingApi::Vulkan:
                break;
            case RenderingApi::DirectX:
                break;
            case RenderingApi::Metall:
                break;
            default:
                YNILA_CORE_LOGGER_CRITICAL("Unknown Rendering API!");
                return nullptr;        
                break;
        }
    }
}