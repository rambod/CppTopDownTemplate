cmake_minimum_required(VERSION 3.26)
project(CppTopDownTemplate)

set(CMAKE_CXX_STANDARD 23)

find_package(raylib CONFIG REQUIRED)
add_executable(CppTopDownTemplate main.cpp
        Character.h
        Character.cpp
        Prop.cpp
        Prop.h)
target_link_libraries(CppTopDownTemplate PRIVATE raylib)
add_custom_command(TARGET CppTopDownTemplate POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:CppTopDownTemplate>/assets)