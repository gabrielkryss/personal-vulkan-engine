# Personal Vulkan Engine Project

Welcome to my personal Vulkan engine project! This repository is my playground for learning and experimenting with Vulkan and modern C++. My goal is to understand Vulkan concepts and build a simple graphics engine from scratch, which will gradually evolve into a basic game engine. This is a long-term, evolving project where I experiment with and test new game technologies and techniques. While you shouldn't expect everything to be polished, I aim to write maintainable code to the best of my current knowledge.

## Table of Contents

1. [Checklist](#checklist)
3. [How to Run](#how-to-run)

## Checklist

- [x] Learn Vulkan concepts and set up very simple infrastructure code.
- [x] Construct a simple render pipeline:
  - [x] Compile fragment and vertex shaders to SPIR-V.
  - [x] Learn about and implement synchronization structures.
- [x] Implement multithreaded rendering by having more semaphores and fences owned by images.
- [x] Draw a triangle on the screen.
- [x] Draw multiple triangles on the screen.
- [ ] ......
- [ ] Textures
- [ ] ......
- [ ] Support DX12 (would have to rename the project at this point)
- [ ] Construct ray tracing pipeline
- [ ] Implement Nanite, Rendering Meshlets
- [ ] ......
- [ ] Entity Component System
- [ ] ......
- [ ] Design Game Engine API
- [ ] ......
- [ ] Font Rendering
- [ ] ......
- [ ] Input Handling
- [ ] ......
- [ ] Audio
- [ ] ......
- [ ] Networking
- [ ] Physics

## How to run

To get started with this project, clone the repository and follow the setup instructions provided in the respective directories. Feedback is always welcome! 

### Requirements

Install Vulkan SDK from LunarG. Disclaimer I have only tested this project on Windows 11.

```sh
git clone [https://github.com/your-username/vulkan-engine.git](https://github.com/gabrielkryss/personal-vulkan-engine.git)
cd personal-vulkan-engine/
```
I use conan2 to install dependencies
```sh
conan install . --profile="custom_conan_profile" --build=missing 
```
go into the build directory
```sh
cd build
```
Generate build scripts
```sh
cmake .. -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE="generators/conan_toolchain.cmake"
```
Build the project
```sh
cmake --build . --config Release --clean-first
```
Run executable
```
./Release/MyProject.exe
```
