#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <utility>
#include <vector>
#include "vendor/glad/include/glad/gl.h"
#include<vendor/glm/glm/gtc/matrix_transform.hpp>
#include<vendor/glm/glm/gtc/type_ptr.hpp>

namespace Ynila {
	class Shader
	{
	public:
		Shader(const std::string& filepath);
		Shader(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource);
		~Shader() = default;
		void Bind();
		void Unbind();
		void UploadUniformFloat4(const std::string& name, const glm::vec4& value);
	private:
		void Compile(const std::vector<std::pair<int, std::string>>& sourceMap);
	private:
		std::string m_Name;
		uint32_t m_Program;
	};
} // namespace Ynila
#endif // !SHADER_H
