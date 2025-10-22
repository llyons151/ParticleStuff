# Cool Particle Stuff
### Real-Time Particle Playground (OpenGL)

A fast, tweakable particle sandbox written in **C++17 + OpenGL**.  
It renders large particle counts and lets you experiment with procedural “wave” fields and gravity-style motion.


https://github.com/user-attachments/assets/a3062f65-c800-4990-91bc-4fde497d8fe6


![Untitled design(1)](https://github.com/user-attachments/assets/3436b520-b868-4c3f-83ee-27df2cc5a22d)

---

## 🧱 Project Layout
```bash
.
├─ CMakeLists.txt
├─ include/
│  ├─ core/window.hpp
│  ├─ core/shader.hpp
│  └─ graphics/
│      ├─ particle.hpp
│      ├─ particleRenderer.hpp
│      └─ particleManager.hpp
├─ src/
│  ├─ main.cpp
│  ├─ core/
│  │   ├─ window.cpp
│  │   └─ shader.cpp
│  └─ graphics/
│      ├─ particle.cpp
│      ├─ particleRenderer.cpp
│      └─ particleManager.cpp
└─ shaders/
   ├─ basic.vert
   └─ basic.frag
```
## ⚙️ Dependencies
```bash
  C++17 toolchain (gcc / clang / MSVC)
  CMake ≥ 3.16
  OpenGL 3.3+ capable GPU + drivers
  GLFW, GLAD, GLM
```
## Arch Linux Setup
```bash
sudo pacman -S --needed base-devel cmake glfw-x11 glm git

git clone https://github.com/yourname/GravitySim.git
cd GravitySim

cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j

./build/GravitySim 250000
```
## How It Works:
  Particle – simple POD struct storing position & velocity (graphics/particle.hpp)
  
  ParticleRenderer – owns GPU buffers, uploads particle positions, and draws them
  
  ParticleManager – updates particle states every frame; includes multiple “wave” patterns

## Example Update Function:
// graphics/particleManager.cpp
void ParticleManager::wave1(std::vector<Particle>& particles) {
    for (auto& p : particles) {
        p.m_x += std::sin(p.m_y * 2.0f + glfwGetTime()) * 0.02f;
        p.m_y += std::cos(p.m_x * 2.0f - glfwGetTime()) * 0.02f;
        p.m_z += std::cos(p.m_z * 2.0f - glfwGetTime()) * 0.02f;
    }
}
Call particleManager.(desired wave function) in main game loop
Add as many custom “wave” functions as you like — each one defines a unique motion pattern.
