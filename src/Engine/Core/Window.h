#ifndef YNILA_WINDOW_H
#define YNILA_WINDOW_H

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
        static Window* CreateWindow();

        virtual void OnUpdate() = 0;
    private:
        static RenderingApi m_renderingApi;
    };

} // namespace Ynila

#endif //YNILA_WINDOW_H
