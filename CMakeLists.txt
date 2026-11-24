cmake_minimum_required(VERSION 3.16)
project(opencode-token-pool CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(opencodetokenpool
    src/main.cpp
    src/pool.cpp
    src/rotate.cpp
    src/inject.cpp
    src/cli.cpp
)

target_include_directories(opencodetokenpool PRIVATE include)

if(WIN32)
    target_link_libraries(opencodetokenpool PRIVATE userenv)
endif()
