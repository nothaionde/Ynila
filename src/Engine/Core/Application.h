#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"

namespace Ynila {
    class Application
    {
    public:
        Application();

        ~Application() = default;

        void Run();

        static Application &GetInstance()
        {
            return *s_Instance;
        };

        Window &GetWindow()
        {
            return *m_Window;
        }

    private:
        Window *m_Window;
        static Application *s_Instance;
    };
} // namespace Ynila

#endif // APPLICATION_H
