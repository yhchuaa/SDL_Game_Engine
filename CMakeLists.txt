cmake_minimum_required(VERSION 3.20.0)

# set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")
# set(CMAKE_PREFIX_PATH "C:/dev/vcpkg/installed/x64-mingw-dynamic/share")
set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic")   

project(main)

find_package(SDL2 CONFIG REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_image CONFIG REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(main src/main.cpp src/Game.cpp src/TextureManager.cpp src/GameObj.cpp src/Map.cpp)
target_link_libraries(main PRIVATE ${SDL2_LIBRARIES} SDL2_image::SDL2_image)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)