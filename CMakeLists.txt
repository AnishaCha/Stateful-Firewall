cmake_minimum_required(VERSION 3.10)
project(StatefulFirewall)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(firewall
    src/main.cpp
    src/firewall.cpp
    src/utils.cpp
)
