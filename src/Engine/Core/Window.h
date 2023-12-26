#ifndef YNILA_WINDOW_H
#define YNILA_WINDOW_H

#include <cstdint>

namespace Ynila {
    enum class RenderingApi
    {
        OpenGL,
        Vulkan,
        DirectX,
        Metall
    };

    class Window
    {
    public:
        virtual ~Window() = default;

        static Window *CreateWindow();

        virtual void OnUpdate() = 0;

        virtual bool ShouldClose() = 0;

        virtual void Terminate() = 0;

        virtual void Initialize() = 0;

        virtual void *GetNativeWindow() const = 0;

        virtual uint32_t GetWidth() const = 0;

        virtual uint32_t GetHeight() const = 0;
    private:
        static RenderingApi m_renderingApi;
    };
} // namespace Ynila

#endif //YNILA_WINDOW_H
