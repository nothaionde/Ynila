#ifndef GLFWWINDOW_H_
#define GLFWWINDOW_H_

#include "src/Engine/Core/Window.h"
#include "glad/gl.h"
// GLFW (include after glad)
#include "GLFW/glfw3.h"

namespace Ynila {


	class WinWindow : public Window
	{
	public:
		WinWindow();
		~WinWindow() override = default;
		void OnUpdate() override;
	};
}

#endif // !GLFWWINDOW_H_
