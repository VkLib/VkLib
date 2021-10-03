# Copyright(c) 2021 - ぱんじすた All rights reserved.

cmake_minimum_required(VERSION 3.20.4)

set(PROJECT_NAME VkLibCheck)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS

)

set(SOURCES
    src/main.cpp
)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

# インクルード

# リンカー
include_directories("../VkLib/src")

link_directories("../VkLib/build/Debug")

add_executable(${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
)

target_link_libraries(${PROJECT_NAME} "VkLib")