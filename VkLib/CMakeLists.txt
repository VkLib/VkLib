# Copyright(c) 2021 - ぱんじすた All rights reserved.

cmake_minimum_required(VERSION 3.20.4)

set(PROJECT_NAME VkLib)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
    src/VkLib.h
)

set(SOURCES
    src/VkLib.cpp
)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

# インクルード
include_directories("C:/VulkanSDK/1.2.182.0/Include")
include_directories("C:/GLFW/glfw-3.3.4/include")

# リンカー
link_directories("C:/VulkanSDK/1.2.182.0/Bin" "C:/VulkanSDK/1.2.182.0/Lib")
link_directories("C:/GLFW/glfw-3.3.4.bin.WIN64/lib-vc2019")

add_library(${PROJECT_NAME} SHARED
    ${HEADERS}
    ${SOURCES}
)

target_link_libraries(${PROJECT_NAME} "glfw3" "vulkan-1")