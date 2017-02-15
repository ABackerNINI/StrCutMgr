cmake_minimum_required(VERSION 3.6)
project(StrCutMgr)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE
        Source/StrCutMgr.cpp
        Source/StrCutMgr.h
        )

add_executable(StrCutMgr main.cpp
        ${SOURCE}
        )