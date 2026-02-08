#ifndef GUARDGL_SHADER_MANAGER_HPP
#define GUARDGL_SHADER_MANAGER_HPP

#include <string>
#include <unordered_map>

class Shader {
private:
    unsigned int m_RendererID;
public:
    Shader(const std::string& vCode, const std::string& fCode);
    ~Shader();

    Shader(Shader&& other) noexcept;
    Shader& operator=(Shader&& other) noexcept;

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    void Bind() const;
    void Unbind() const;
};

class ShaderManager {
private:
    std::unordered_map<std::string, Shader> m_Shaders;
public:
    void Load(const std::string& name, const std::string& vPath, const std::string& fPath);
    Shader& Get(const std::string& name);
};

#endif
