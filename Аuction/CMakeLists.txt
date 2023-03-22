cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
project("Auction")

file(GLOB AUCTION_SRC "Auction/src/*")
add_executable(main ${AUCTION_SRC})
target_include_directories(main PRIVATE "Auction/include")