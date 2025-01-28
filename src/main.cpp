/*import std.core;*/
import MyClass;

#include <GLFW/glfw3.h>
#include <entt/entt.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <spdlog/spdlog.h>
#include <vulkan/vulkan.h>

#include "app.h"

/*#include <iostream>*/
import std;

struct Position {
  float x;
  float y;
};

struct Velocity {
  float dx;
  float dy;
};

int main() {
  std::print("Hello, World!\n");

#ifdef NDEBUG
  printf("Release configuration!\n");
#else
  printf("Debug configuration!\n");
#endif

  MyClass myClass;
  myClass.sayHello();

  // spdlog example
  spdlog::info("This is an info message from spdlog.");
  spdlog::warn("This is a warning message from spdlog.");
  spdlog::error("This is an error message from spdlog.");
  spdlog::debug("This is a debug message from spdlog.");
  spdlog::critical("This is a critical message from spdlog.");

  // glm example
  // Create two vectors
  glm::vec3 vec1(1.0f, 2.0f, 3.0f);
  glm::vec3 vec2(4.0f, 5.0f, 6.0f);

  // Vector addition
  glm::vec3 vecSum = vec1 + vec2;
  std::print("Vector Sum: ({}, {}, {})\n", vecSum.x, vecSum.y, vecSum.z);

  // Vector dot product
  float dotProduct = glm::dot(vec1, vec2);
  std::print("Dot Product: {}\n", dotProduct);

  // Vector cross product
  glm::vec3 crossProduct = glm::cross(vec1, vec2);
  std::print("Cross Product: ({}, {}, {})\n", crossProduct.x, crossProduct.y,
             crossProduct.z);

  // Matrix transformation
  glm::mat4 transform = glm::mat4(1.0f);
  transform = glm::translate(transform, glm::vec3(1.0f, 1.0f, 1.0f));
  glm::vec4 transformedVec = transform * glm::vec4(vec1, 1.0f);
  std::print("Transformed Vector: ({}, {}, {})\n", transformedVec.x,
             transformedVec.y, transformedVec.z);

  // entt example
  entt::registry registry;
  auto entity = registry.create();
  registry.emplace<Position>(entity, 0.0f, 0.0f);
  registry.emplace<Velocity>(entity, 1.0f, 1.0f);
  auto &pos = registry.get<Position>(entity);
  auto &vel = registry.get<Velocity>(entity);
  pos.x += vel.dx;
  pos.y += vel.dy;
  std::print("Updated Position: ({}, {})\n", pos.x, pos.y);

  // Initialize Vulkan
  VkInstance instance;
  VkApplicationInfo appInfo{};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Vulkan Example";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "No Engine";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

  if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
    std::cerr << "Failed to create Vulkan instance!" << std::endl;
    return -1;
  }

  // Enumerate physical devices (GPUs)
  uint32_t deviceCount = 0;
  vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

  if (deviceCount == 0) {
    std::cerr << "Failed to find GPUs with Vulkan support!" << std::endl;
    return -1;
  }

  std::vector<VkPhysicalDevice> devices(deviceCount);
  vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

  std::cout << "Found " << deviceCount
            << " GPU(s) with Vulkan support:" << std::endl;
  for (const auto &device : devices) {
    VkPhysicalDeviceProperties deviceProperties;
    vkGetPhysicalDeviceProperties(device, &deviceProperties);
    std::cout << "\t" << deviceProperties.deviceName << std::endl;
  }

  // Clean up Vulkan instance
  vkDestroyInstance(instance, nullptr);

  App *myApp = new App(640, 480, true);

  myApp->run();
  delete myApp;

  return 0;
}
