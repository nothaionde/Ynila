#ifndef SCENE_H
#define SCENE_H

#include <memory>

#include "src/Engine/Graphics/GUI/Gui.h"

namespace Ynila {
    class Scene
    {
    public:
        Scene();

        void OnUpdate();

    private:
        std::unique_ptr<Gui> m_Gui;
    };
}

#endif // !SCENE_H
