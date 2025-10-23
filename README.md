# Cool Particle Stuff
### Real-Time Particle Playground (OpenGL)

A fast, tweakable particle sandbox written in **C++17 + OpenGL**.  
It renders large particle counts and lets you experiment with procedural “wave” fields and gravity-style motion

![Untitled design(4)(1)](https://github.com/user-attachments/assets/af023e1e-8aa3-49f7-ba2a-7f5f5c22efff)

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
