# Copyright(c) 2021 - ぱんじすた All rights reserved.

cmake_minimum_required(VERSION 3.20.4)

project(VkLib)

set(HEADERS
    src/VkLib/VkLib.h
)

set(SOURCES
    src/VkLib/VkLib.cpp
)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})


# 
# add_executable(VkLib
#    src/main.cpp
add_library(VkLib STATIC
    ${HEADERS}
    ${SOURCES}
    )