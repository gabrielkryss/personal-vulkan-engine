cmake_minimum_required(VERSION 3.31)
project(MyProject LANGUAGES CXX)

# Enable C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# setting toolchain file here doesn't seem to work but doing it in commmand line -DCMAKE_TOOLCHAIN_FILE works?
# set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake")

message("CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message("CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message("CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")

# Find packages
# find_package(Vulkan REQUIRED)
find_package(spdlog REQUIRED)
find_package(EnTT REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

# Add source files
add_executable(${PROJECT_NAME}
  main.cpp
  src/MyClass.cpp
  view/engine.cpp
  control/app.cpp
  model/scene.cpp
  view/vkUtil/memory.cpp
  control/logging.cpp
  model/vertex_menagerie.cpp
  view/vkImage/image.cpp
  view/vkUtil/single_time_commands.cpp
  view/vkInit/descriptors.cpp
  view/vkUtil/frame.cpp
)

# Add header and interface files
target_sources(${PROJECT_NAME} PRIVATE
  include/MyClass.ixx
  view/engine.h
  view/vkInit/instance.h
  config.h
  control/logging.h
  view/vkInit/device.h
  view/vkUtil/queue_families.h
  view/vkInit/swapchain.h
  view/vkUtil/frame.h
  view/vkUtil/shaders.h
  view/vkInit/pipeline.h
  view/vkInit/framebuffer.h
  view/vkInit/sync.h
  view/vkInit/commands.h
  control/app.h
  view/vkUtil/render_structs.h
  model/scene.h
  view/vkUtil/memory.h
  view/vkMesh/mesh.h
  model/vertex_menagerie.h
  view/vkImage/image.h
  view/vkImage/stb_image.h
  view/vkUtil/single_time_commands.h
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE
  # Vulkan::Vulkan
  spdlog::spdlog
  EnTT::EnTT
  glfw
  glm
)

# Add examples
# add_subdirectory(examples/example1)
# add_subdirectory(examples/example2)
