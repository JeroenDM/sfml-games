cmake_minimum_required(VERSION 3.10)
project(pong)

set(CMAKE_CXX_STANDARD 17)

set(MESA_GL_VERSION_OVERRIDE 4.5)
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})

find_package(SFML REQUIRED network audio graphics window system)
include_directories(${SFML_INCLUDE_DIR} include)

add_library(game src/bat.cc src/hud.cc src/ball.cc)


add_executable(main main.cc)
target_link_libraries(main game sfml-graphics sfml-window sfml-system sfml-audio)