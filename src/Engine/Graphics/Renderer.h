#ifndef RENDERER_H
#define RENDERER_H

#include<vendor/glm/glm/gtc/matrix_transform.hpp>
#include<vendor/glm/glm/gtc/type_ptr.hpp>
#include<vendor/glad/include/glad/gl.h>
#include "src/Engine/Core/Logger.h"
#include "src/Engine/Graphics/Shader.h"
#include "src/Engine/Graphics/Camera.h"

namespace Ynila {

    class Renderer
    {
    public:
        static void Initialize();
        static void BeginScene(const Camera camera);
		static void EndScene();
        static void DrawTriangle(const glm::vec3 &position, const glm::vec4 &color);
        static glm::vec3 pos;
        static glm::vec4 color;
	private:
        static GLuint VBO, VAO;
        static int shaderProgram;
        static std::unique_ptr<Shader> shader;
    };

} // namespace Ynila

#endif // !RENDERER_H
