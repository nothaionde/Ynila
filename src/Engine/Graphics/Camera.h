#ifndef CAMERA_H
#define CAMERA_H

#include <vendor/glm/glm/glm.hpp>
#include <vendor/glm/glm/gtc/matrix_transform.hpp>

namespace Ynila {

    class Camera
    {
    public:
        Camera();
        ~Camera() = default;

        void MoveForward(float distance);
        void MoveBackward(float distance);
        void MoveLeft(float distance);
        void MoveRight(float distance);
        void MoveUp(float distance);
        void MoveDown(float distance);
        void SetPosition(const glm::vec3& position);
        void SetDirection(const glm::vec3& direction);
        void Rotate(float angle, const glm::vec3& axis);
        glm::mat4 GetViewMatrix() const;
        glm::mat4 GetProjectionMatrix() const;

    protected:
        glm::vec3 m_Position;
        glm::vec3 m_Direction;
        glm::vec3 m_Up;
        float m_Fov;
		float m_Aspect;
        float m_Near;
		float m_Far;
    };

} // namespace Ynila

#endif // !CAMERA_H