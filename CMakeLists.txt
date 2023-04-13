cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
project("Races")

file(GLOB GRAPHICS_SDL_SRC "graphics_sdl/src/*")
add_executable(main ${GRAPHICS_SDL_SRC})
target_include_directories(main PRIVATE "graphics_sdl/include")

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(main
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

#find_package(spdlog CONFIG REQUIRED)
#target_link_libraries(main PRIVATE spdlog::spdlog spdlog::spdlog_header_only)