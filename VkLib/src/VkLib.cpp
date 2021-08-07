#define GLFW_INCLUDE_VULKAN

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include "VkLib.h"

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include <GLFW/glfw3.h>

#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>

#define DEFAULT_TITLE_TEXT "VkLib"


using namespace std;

class VkLibManage {
public:
    void Init() {
        
    }
    const TCHAR* GetWindowTitle() {
        return m_titleText.c_str();
    }
    void SetWindowTitle(const TCHAR* title) {
        m_titleText = title;
    }

    int32_t GetResizable() {
        return m_resizable;
    }

    void SetResizable(int32_t resizable) {
        this->m_resizable = resizable;
    }

    void End() {

    }

private:
    std::string m_titleText = "VkLib";
    int32_t m_resizable = 1;
    bool m_isInitialized;
};

namespace {
    VkLibManage manage;

    bool isInitialized;
    GLFWwindow* window;
    VkInstance instance;
}

namespace VkLib {
    int32_t VkLib_Init() {
        
        VkResult ret;

        // GLFW初期化
        glfwInit();        
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, manage.GetResizable());
        
        // TODO: ウィンドウがここで表示されてしまうため、
        // 今後線宣言場所を変更する。
        window = glfwCreateWindow(960, 540, manage.GetWindowTitle(), nullptr, nullptr);

        VkApplicationInfo aInfo;
        aInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        aInfo.pNext = nullptr;
        aInfo.pApplicationName = "VkLib";
        aInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        aInfo.pEngineName = "No Engine";
        aInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        aInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);


        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        VkInstanceCreateInfo cinfo;
        cinfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        cinfo.pNext = nullptr;
        cinfo.flags = 0;
        cinfo.pApplicationInfo = &aInfo;
        cinfo.enabledExtensionCount = glfwExtensionCount;
        cinfo.ppEnabledExtensionNames = glfwExtensions;
        cinfo.enabledLayerCount = 0;
        cinfo.ppEnabledLayerNames = nullptr;

        ret = vkCreateInstance(&cinfo, nullptr, &instance);

        if(ret != VK_SUCCESS) {
            return -3;
        }

        uint32_t extensionCount;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

        std::vector<VkExtensionProperties> extensions(extensionCount);

        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());


        // uint32_t physicalDeviceArraySize;
        // vkEnumeratePhysicalDevices(instance, &physicalDeviceArraySize, nullptr);

        // std::vector<VkPhysicalDevice> physicalDeviceArray(physicalDeviceArraySize);        
        // vkEnumeratePhysicalDevices(instance, &physicalDeviceArraySize, physicalDeviceArray.data());

        isInitialized = true;
        return 0;
    }

    int32_t VkLib_IsInit() {
        return isInitialized ? TRUE : FALSE;
    }

    int32_t ProcessMessage() {

        glfwPollEvents();

        return glfwWindowShouldClose(window);
    }

    int32_t SetWindowText(const TCHAR* title) {
        manage.SetWindowTitle(title);

        if(isInitialized) {
            glfwSetWindowTitle(window, manage.GetWindowTitle());
        }

        return TRUE;
    }

    int32_t VkLib_End() {
        vkDestroyInstance(instance, nullptr);

        glfwDestroyWindow(window);

        glfwTerminate();

        isInitialized = false;
        return 0;
    }
}

