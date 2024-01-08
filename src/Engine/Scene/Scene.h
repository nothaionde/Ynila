#ifndef SCENE_H
#define SCENE_H

#include <memory>

#include <vendor/glm/glm/gtc/type_ptr.hpp>

#include "src/Engine/Graphics/GUI/Gui.h"

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
        static Scene *Instance;
        glm::vec3 pos = {1.0f, 1.0f, 1.0f};
        glm::vec4 color = {1.0f, 1.0f, 1.0f, 1.0f};
    private:
        std::unique_ptr<Gui> m_Gui;
    };
} // namespace Ynila

#endif // !SCENE_H
