cmake_minimum_required(VERSION 3.20.4)

project(VkLib)
add_subdirectory(src)
# set_target_properties(VkLib PROPERTIES
#     VERSION ${PROJECT_VERSION}
#     SOVERSION 1
#     PUBLIC_HEADER src/Image.hpp)