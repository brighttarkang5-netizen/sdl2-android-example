cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2/include

    # SDL_internal.h is located in src required by SDL_android_main.c bridge
    ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2/src

    ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_image/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_gfx/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_mixer/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_ttf/include
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../SDL2/ ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_image/ ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_image)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_gfx/ ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_gfx)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_mixer/ ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_mixer)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_ttf/ ${CMAKE_CURRENT_SOURCE_DIR}/../SDL2_ttf)

add_library(
    main
    SHARED
    src/snake.cpp
    src/SDL_android_main.c
)

find_library(
    log-lib
    log
)

target_link_libraries(
    main
    SDL2
    SDL2_image
    SDL2_gfx
    SDL2_mixer
    SDL2_ttf
    ${log-lib}
)
