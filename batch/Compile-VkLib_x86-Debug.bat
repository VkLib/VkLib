::variables
set VULKAN_VERSION=1.2.182.0

chcp 65001

cd ..
mkdir "VkLib/bin/x86/Debug"
C:/MinGW/Bin/g++.exe VkLib/src/** ^
-g ^
-IC:/VulkanSDK/%VULKAN_VERSION%/Include/ ^
-LC:/VulkanSDK/%VULKAN_VERSION%/Lib32/ ^
-IC:/GLFW/glfw-3.3.4/include/ ^
-LC:/GLFW/glfw-3.3.4/lib-mingw/ ^
-o ^
VkLib/bin/x86/Debug/VkLib.dll ^
-lvulkan-1 ^
-lglfw3dll ^
-shared ^
"-Wl,--out-implib,VkLib/bin/x86/Debug/VkLib.lib"

cd %~dp0