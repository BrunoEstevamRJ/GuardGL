#include "ShaderManager.hpp"
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


Shader::Shader(const std::string& vCode, const std::string& fCode) {
    const char* vSource = vCode.c_str();
    const char* fSource = fCode.c_str();

    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vSource, nullptr);
    glCompileShader(vs);

    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fSource, nullptr);
    glCompileShader(fs);

    m_RendererID = glCreateProgram();
    glAttachShader(m_RendererID, vs);
    glAttachShader(m_RendererID, fs);
    glLinkProgram(m_RendererID);

    glDeleteShader(vs);
    glDeleteShader(fs);
}

Shader::~Shader() {
    if (m_RendererID != 0) {
        glDeleteProgram(m_RendererID);
    }
}

Shader::Shader(Shader&& other) noexcept : m_RendererID(other.m_RendererID) {
    other.m_RendererID = 0; // "Rouba" o ID e zera o original
}

Shader& Shader::operator=(Shader&& other) noexcept {
    if (this != &other) {
        glDeleteProgram(m_RendererID); // Limpa o atual
        m_RendererID = other.m_RendererID;
        other.m_RendererID = 0;
    }
    return *this;
}

void Shader::Bind() const { glUseProgram(m_RendererID); }
void Shader::Unbind() const { glUseProgram(0); }



void ShaderManager::Load(const std::string& name, const std::string& vPath, const std::string& fPath) {
    auto readFile = [](const std::string& path) {
        std::ifstream file(path);
        std::stringstream ss;
        ss << file.rdbuf();
        return ss.str();
    };

    std::string vCode = readFile(vPath);
    std::string fCode = readFile(fPath);

    m_Shaders.emplace(std::piecewise_construct,
                      std::forward_as_tuple(name),
                      std::forward_as_tuple(vCode, fCode));
}

Shader& ShaderManager::Get(const std::string& name) {
    return m_Shaders.at(name);
}
