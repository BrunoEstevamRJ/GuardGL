# GuardGL

**GuardGL** is a small Modern C++ library that provides **safe OpenGL resource management**
using **RAII** and **move-only semantics**.

The goal is simple:  
> prevent OpenGL resource leaks and make ownership explicit.

---

## ✨ Why GuardGL?

Raw OpenGL resource management is error-prone:

- you must manually call `glDelete*`
- it's easy to leak textures/buffers/programs
- ownership is often unclear
- copying handles is dangerous

GuardGL solves this by wrapping OpenGL objects into **RAII guards**:

- created in constructors
- automatically destroyed in destructors
- **non-copyable**
- **movable**
- explicit ownership transfer

---

## ✅ Features

- **RAII-based** OpenGL resource wrappers
- **Move-only** ownership (no accidental copies)
- Clear lifetime rules
- Minimal and lightweight design
- Modern C++ style (C++17+ friendly)

---

## 🧠 Core Idea (RAII + Ownership)

Instead of writing:

```cpp
GLuint tex = 0;
glGenTextures(1, &tex);

// ... use tex ...

glDeleteTextures(1, &tex); // easy to forget




You use a guard:

auto tex = GuardTexture{};


And the resource is destroyed automatically when it leaves scope.

🧩 Example (Concept)
#include "GuardGL.hpp"

int main() {
    GuardTexture texture;

    texture.bind();
    // ... upload data ...

    // texture is automatically deleted here
}


The exact API depends on the resource type, but the principle stays the same:
resource lifetime is tied to object lifetime.

🔥 Move-only semantics

GuardGL objects are non-copyable, but movable:

GuardTexture a;

// GuardTexture b = a;   ❌ not allowed (copy)
GuardTexture b = std::move(a);  // ✅ ownership transfer


This makes ownership explicit and prevents double-deletes.

🛠️ Build / Integration

This project is meant to be simple to integrate.

Requirements

C++17 compiler

OpenGL

(Optional) GL loader like GLAD / GLEW

Build

If you use CMake:

mkdir build
cd build
cmake ..
cmake --build .

📌 Roadmap

Add more OpenGL guards (textures, buffers, VAOs, shaders, programs)

Improve examples / demo project

Add basic tests

Add CI (GitHub Actions)

🎯 Motivation

This project exists as a learning + portfolio piece focused on:

Modern C++

RAII

Ownership / Lifetime

OpenGL / Graphics Programming

📄 License

MIT License.


🔥 Agora é só:

```bash
git add README.md
git commit -m "docs: add README explaining GuardGL design and RAII"
git push

