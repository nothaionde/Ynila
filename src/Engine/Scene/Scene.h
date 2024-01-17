#ifndef SCENE_H
#define SCENE_H

#include <memory>

#include <vendor/glm/glm/gtc/type_ptr.hpp>

#include "src/Engine/Graphics/GUI/Gui.h"
#include "src/Engine/Graphics/Camera.h"

namespace Ynila {
    class Scene
    {
    public:
        Scene();

        void OnUpdate();

        static Scene *GetInstance()
        {
            return Instance;
        }

    public:
        std::unique_ptr<Camera> m_Camera;
    private:
        static Scene *Instance;
        std::unique_ptr<Gui> m_Gui;
    };
} // namespace Ynila

#endif // !SCENE_H
