#include "Scene.h"

namespace Ynila {
    Scene::Scene()
    {
        m_Gui = std::make_unique<Gui>();
		m_Gui->Initialize();
    }

    void Scene::OnUpdate()
    {
        m_Gui->Update();
    }
}