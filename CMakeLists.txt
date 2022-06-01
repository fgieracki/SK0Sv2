
cmake_minimum_required(VERSION 3.22)
project(SK0Sv2)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED IMPORTED_TARGET "gtk+-2.0")

include_directories(.)

add_executable(SK0Sv2
        main.cpp
        Row.cpp
        Row.h
        GUI.cpp
        GUI.h
        Database.cpp
        Database.h)

target_link_libraries(SK0Sv2 PRIVATE PkgConfig::GTK)

