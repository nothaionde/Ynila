#include "WinWindow.h"
#include "src/Engine/Core/Logger.h"

namespace Ynila {
	WinWindow::WinWindow()
	{
		YNILA_CORE_LOGGER_INFO("GLFW Initializtion code: {}", glfwInit());
		
	}
	void WinWindow::OnUpdate()
	{
	}
}