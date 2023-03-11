cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
project("Races")

file(GLOB WINDOW_SRC "window/src/*")
add_executable(main ${WINDOW_SRC})
target_include_directories(main PRIVATE "window/include")

find_package(absl CONFIG REQUIRED)
target_link_libraries(main PRIVATE absl::any absl::log absl::base absl::bits)

find_package(OpenGL REQUIRED)
target_link_libraries(main PRIVATE ${OPENGL_LIBRARIES})
target_include_directories(main PRIVATE ${OPENGL_INCLUDE_DIR})

find_package(OpenGL REQUIRED)
target_link_libraries(main PRIVATE OpenGL::GL)

#find_package(OpenGL REQUIRED COMPONENTS GL      # v3.8
 #                                       GLU     # v3.8
  #                                      GLX     # v3.10
   #                                     EGL     # v3.10
    #                                    OpenGL) # v3.10


#find_package(GLEW REQUIRED)
#target_link_libraries(main PRIVATE GLEW::GLEW)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(main PRIVATE glfw)

#find_package(spdlog CONFIG REQUIRED)
#target_link_libraries(main PRIVATE spdlog::spdlog spdlog::spdlog_header_only)