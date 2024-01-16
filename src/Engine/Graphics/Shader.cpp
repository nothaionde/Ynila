#include "Shader.h"
#include "src/Engine/Core/Logger.h"


namespace Ynila {

    Shader::Shader(const std::string& filepath)
        : m_Name("Shader constructor with filepath " + filepath), m_Program(0)
    {
		// TODO: implement reading shaders from file. Maybe both shaders should be in one file
        YNILA_CORE_LOGGER_ERROR("Reading shaders from file not implemented yet! Use Shader(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource)");
    }
    Shader::Shader(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource)
        : m_Name(name), m_Program(0)
    {
        std::vector<std::pair<int, std::string>> sourceMap;
        sourceMap.push_back(std::make_pair(GL_VERTEX_SHADER, vertexSource));
        sourceMap.push_back(std::make_pair(GL_FRAGMENT_SHADER, fragmentSource));
        Compile(sourceMap);
    }
    void Shader::Bind()
    {
		glUseProgram(m_Program);
    }
    void Shader::Unbind()
    {
        glUseProgram(0);
    }
    void Shader::UploadUniformFloat4(const std::string& name, const glm::vec4& value)
    {
        GLuint colorLocation = glGetUniformLocation(m_Program, name.c_str());
        glUniform4f(colorLocation, value.x, value.y, value.z, value.w);
    }
    void Shader::Compile(const std::vector<std::pair<int, std::string>>& sourceMap)
    {
        std::vector<GLuint> shadersId(sourceMap.size());
        GLuint program = glCreateProgram();
        for (auto it : sourceMap)
        {
            GLenum type = it.first;
            const std::string source = it.second;
            GLuint shader = glCreateShader(type);
            const GLchar* sourceCString = source.c_str();
            glShaderSource(shader, 1, &sourceCString, 0);
            glCompileShader(shader);
            GLint isCompiled = 0;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
            if (isCompiled == GL_FALSE)
            {
                GLint maxLenght = 0;
                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLenght);
                std::vector<GLchar> infoLog(maxLenght);
                glGetShaderInfoLog(shader, maxLenght, &maxLenght, &infoLog[0]);
                glDeleteShader(shader);
                YNILA_CORE_LOGGER_ERROR("Shader compilation failed: {0}", infoLog.data());
            }
            glAttachShader(program, shader);
            shadersId.push_back(shader);
        }
        m_Program = program;
        assert(m_Program != 0);
        glLinkProgram(program);

        GLint isLinked = 0;
        glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);
            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);
            glDeleteProgram(program);

            for (auto id : shadersId)
            {
                glDeleteShader(id);
            }
            YNILA_CORE_LOGGER_ERROR("Shader linking failed: {0}", infoLog.data());
        }

        for (auto id : shadersId)
        {
            glDetachShader(program, id);
        }
    }
} // namespace Ynila