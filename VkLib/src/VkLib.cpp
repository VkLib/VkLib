
#include "VkLib.h"

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include <GLFW/glfw3.h>

#include <vector>
#include <cstdio>

namespace {
    GLFWwindow* window;
}

namespace VkLib {
    int32_t VkLib_Init() {
        
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        window = glfwCreateWindow(960, 540, "VkLib", nullptr, nullptr);


        // VkResult result;

        // VkApplicationInfo aInfo;
        // aInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        // aInfo.pNext = nullptr;
        // aInfo.pApplicationName = "VkLib";
        // aInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        // aInfo.pEngineName = "No Engine";
        // aInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        // aInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);

        // VkInstanceCreateInfo cinfo;
        // cinfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        // cinfo.pNext = nullptr;
        // cinfo.flags = 0;
        // cinfo.pApplicationInfo = &aInfo;

        // VkInstance instance;

        // result = vkCreateInstance(&cinfo, nullptr, &instance);

        // if(result != VK_SUCCESS) {
        //     switch(result) {
        //         case VK_ERROR_EXTENSION_NOT_PRESENT:
        //         {
        //             return -2;
        //         }
        //         break;
        //         default:
        //         {
        //             return -1;
        //         }
        //         break;
        //     }
        // }

        // uint32_t physicalDeviceArraySize;
        // vkEnumeratePhysicalDevices(instance, &physicalDeviceArraySize, nullptr);

        // std::vector<VkPhysicalDevice> physicalDeviceArray(physicalDeviceArraySize);        
        // vkEnumeratePhysicalDevices(instance, &physicalDeviceArraySize, physicalDeviceArray.data());

        return 0;
    }

    int32_t ProcessMessage() {

        glfwPollEvents();

        return glfwWindowShouldClose(window);
    }

    int32_t VkLib_End() {
        glfwDestroyWindow(window);

        glfwTerminate();
        return 0;
    }
}

