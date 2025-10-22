# Set the cmake version
cmake_minimum_required(VERSION 3.16...3.29)

# Set the project name
project(Particles LANGUAGES C CXX)

# Find system packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include(FetchContent)
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 1.0.1  
)
FetchContent_MakeAvailable(glm)

# Link cpp files to compile
set(SOURCES 
    src/glad.c
    src/main.cpp
    src/core/window.cpp
    src/core/camera.cpp
    src/core/shader.cpp
    src/graphics/particle.cpp
    src/graphics/particleRenderer.cpp
    src/graphics/particleManager.cpp
)

# Add executable with sources variable
add_executable(Particles ${SOURCES})

# Set included directories
target_include_directories(Particles
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# Link libraries to project
target_link_libraries(Particles
    PRIVATE
        glfw
        OpenGL::GL
        glm::glm
)

