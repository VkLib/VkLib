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

namespace {
    constexpr int VK_IMAGE_NUM = 65535;
}

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
    int32_t m_width = 960;
    int32_t m_height = 540;

};

namespace {
    VkLibManage manage;

    bool isInitialized;
    GLFWwindow* window;
    VkInstance instance;
    VkPhysicalDevice physicalDevice;
    VkDevice device;

    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif
}

namespace {
    bool checkValidationLayerSupport() {
        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

        for(const char* layerName : validationLayers) {
            bool layerFound = false;

            for(const auto& layerProperties : availableLayers) {
                if(strcmp(layerName, layerProperties.layerName) == 0) {
                    layerFound = true;
                    break;
                }
            }
            
            if(!layerFound) {
                return false;
            }
        }

        return true;
    }

    bool isDeviceSuitable(VkPhysicalDevice device) {
        return true;
    }

    int32_t pickPhysicalDevice() {
        physicalDevice = VK_NULL_HANDLE;

        uint32_t deviceCount = 0;
        vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

        if(deviceCount == 0) {
            return -1; // Vulkan not supported.
        }

        std::vector<VkPhysicalDevice> devices(deviceCount);

        vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

        for(const auto& device : devices) {
            if(isDeviceSuitable(device)) { // TODO: 物理デバイスの評価を行って、最も良い物理デバイスを使うように判定をする
                physicalDevice = device;
                break;
            }
        }

        if(physicalDevice == VK_NULL_HANDLE) {
            return -2; // not found suitable gpu.
        }


    }

    std::vector<const char*> getRequiredExtensions() {
        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

        // デバッグ時のみ追加する拡張
        if(enableValidationLayers) {
            extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
        }

        return extensions;        
    }

    VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT mesasgeType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData) {
        
        // TODO: 受け取った情報をデバッグログに描画したりする。

        return VK_FALSE;
    }
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

        if(enableValidationLayers && !checkValidationLayerSupport()) {
            return -1;
        }


        VkApplicationInfo aInfo;
        aInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        aInfo.pNext = nullptr;
        aInfo.pApplicationName = "VkLib";
        aInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        aInfo.pEngineName = "No Engine";
        aInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        aInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);

        auto extensions = getRequiredExtensions();

        VkInstanceCreateInfo cinfo;
        cinfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        cinfo.pNext = nullptr;
        cinfo.flags = 0;
        cinfo.pApplicationInfo = &aInfo;
        cinfo.enabledExtensionCount = extensions.size();
        cinfo.ppEnabledExtensionNames = extensions.data();

        // 検証層の有効チェック
        if(enableValidationLayers) {
            cinfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
            cinfo.ppEnabledLayerNames = validationLayers.data();
        } else {
            cinfo.enabledLayerCount = 0;
            cinfo.ppEnabledLayerNames = nullptr;
        }

        ret = vkCreateInstance(&cinfo, nullptr, &instance);

        if(ret != VK_SUCCESS) {
            return -3;
        }

        uint32_t extensionCount;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

        std::vector<VkExtensionProperties> extensionsProperties(extensionCount);

        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensionsProperties.data());


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


    /////////////////////////////////
    // Graphics
    /////////////////////////////////
    
    /**
     * @if ja-JP
     * @brief 画像ファイルをロードする
     * 
     * @param pFilePath ファイルパス
     * @return int32_t 1以上: 画像ハンドル, -1: 読込失敗
     * @endif
     */
    int32_t LoadGraph(const char* pFilePath);

    /**
     * @brief 画像を描画する
     * 
     * @param x X座標
     * @param y Y座標
     * @param handle 画像ハンドル
     * @return int32_t 
     */
    int32_t DrawGraph(int x, int y, int handle);
}

