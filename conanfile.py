from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.microsoft import MSBuildToolchain, MSBuild, vs_layout
from conan.tools.env import VirtualBuildEnv

class HelloWorldProjectConan(ConanFile):
    name = "HelloWorldProject"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    options = {"layout": ["cmake", "vs"]}
    default_options = {"layout": "cmake"}

    def requirements(self):
        self.requires("spdlog/1.14.1")
        self.requires("entt/3.13.2")
        self.requires("glfw/3.4")
        self.requires("glm/cci.20230113")
        self.requires("vulkan-headers/1.3.290.0")
        self.requires("vulkan-loader/1.3.290.0")

    def build_requirements(self):
        self.tool_requires("cmake/3.31.0")

    def generate(self):
        env = VirtualBuildEnv(self)
        env.generate()

        if self.options.layout == "cmake":
            tc = CMakeToolchain(self)
            tc.generate()
            deps = CMakeDeps(self)
            deps.generate()
        elif self.options.layout == "vs":
            tc = MSBuildToolchain(self)
            tc.generate()

        self.conf.define("tools.env.virtualenv:powershell", True)

    def build(self):
        if self.options.layout == "cmake":
            cmake = CMake(self)
            cmake.configure()
            cmake.build()
        elif self.options.layout == "vs":
            msbuild = MSBuild(self)
            msbuild.build()

    def layout(self):
        if self.options.layout == "cmake":
            cmake_layout(self)
        elif self.options.layout == "vs":
            vs_layout(self)
