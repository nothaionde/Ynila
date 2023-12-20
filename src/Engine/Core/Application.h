#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"

namespace Ynila {
    class Application
    {
    public:
        Application();

        ~Application() = default;

    private:
        Window *m_Window;
    };
}

#endif // APPLICATION_H