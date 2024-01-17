#include "Camera.h"

namespace Ynila {

    Camera::Camera()
        : m_Position(glm::vec3(0.0f, 0.0f, 0.0f)),
        m_Direction(glm::vec3(0.0f, 0.0f, -1.0f)),
        m_Up(glm::vec3(0.0f, 1.0f, 0.0f)),
		m_Fov(60), m_Aspect(16.0f / 9.0f), m_Near(0.1f), m_Far(100.0f)
    {
    }

    void Camera::MoveForward(float distance)
    {
        m_Position += distance * m_Direction;
    }

    void Camera::MoveBackward(float distance)
    {
        m_Position -= distance * m_Direction;
    }

    void Camera::MoveLeft(float distance)
    {
        glm::vec3 left = glm::cross(m_Up, m_Direction);
        m_Position -= distance * left;
    }

    void Camera::MoveRight(float distance)
    {
        glm::vec3 right = glm::cross(m_Direction, m_Up);
        m_Position += distance * right;
    }

    void Camera::MoveUp(float distance)
    {
        m_Position += distance * m_Up;
    }

    void Camera::MoveDown(float distance)
    {
        m_Position -= distance * m_Up;
    }

    void Camera::SetPosition(const glm::vec3& position)
    {
        m_Position = position;
    }

    void Camera::SetDirection(const glm::vec3& direction)
    {
        m_Direction = glm::normalize(direction);
    }

    void Camera::Rotate(float angle, const glm::vec3& axis)
    {
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axis);
        m_Direction = glm::normalize(glm::vec3(rotationMatrix * glm::vec4(m_Direction, 0.0f)));
        m_Up = glm::normalize(glm::vec3(rotationMatrix * glm::vec4(m_Up, 0.0f)));

    }

    glm::mat4 Camera::GetViewMatrix() const
    {
        return glm::lookAt(m_Position, m_Position + m_Direction, m_Up);
    }

    glm::mat4 Camera::GetProjectionMatrix() const
    {
        return glm::perspective(glm::radians(m_Fov), m_Aspect, m_Near, m_Far);
    }

} // namespace Ynila