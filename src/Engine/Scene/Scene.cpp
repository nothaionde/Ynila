#include "Scene.h"
#include "src/Engine/Graphics/Renderer.h"

namespace Ynila {

    Scene *Scene::Instance = nullptr;

    Scene::Scene()
    {
        m_Gui = std::make_unique<Gui>();
        m_Gui->Initialize();
        Instance = this;
    }

    void Scene::OnUpdate()
    {
        Renderer::DrawTriangle(pos, color);

        m_Gui->Update();
    }
} // namespace Ynila