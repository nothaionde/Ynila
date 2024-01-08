#ifndef RENDERER_H
#define RENDERER_H

#include<vendor/glm/glm/gtc/matrix_transform.hpp>
#include<vendor/glm/glm/gtc/type_ptr.hpp>
#include<vendor/glad/include/glad/gl.h>

namespace Ynila {

    class Renderer
    {
    public:
        static void Initialize();

        static void DrawTriangle(const glm::vec3 &position, const glm::vec4 &color);
    };

} // namespace Ynila

#endif // !RENDERER_H
