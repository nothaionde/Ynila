#ifndef GUI_H
#define GUI_H

#include "vendor/imgui-docking/imgui.h"
#include "vendor/imgui-docking/backends/imgui_impl_glfw.h"
#include "vendor/imgui-docking/backends/imgui_impl_opengl3.h"

namespace Ynila {
    class Gui
    {
    public:
        Gui();

        void Update();

        void Initialize();
    };
}

#endif // !GUI_H
