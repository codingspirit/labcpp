cmake_minimum_required(VERSION 3.22)
project(lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog REQUIRED)

set(INCS_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(SRCS_DIR ${CMAKE_CURRENT_LIST_DIR}/source)

set(INCS
        ${INCS_DIR}/aws/lab/base/NonCopyable.h
        ${INCS_DIR}/aws/lab/os/FileDescriptor.h
        ${INCS_DIR}/aws/lab/ui/InputDevice.h
        ${INCS_DIR}/aws/lab/utils/Logger.h)
set(SRCS
        ${SRCS_DIR}/aws/lab/os/FileDescriptor.cpp)

add_library(lab SHARED ${SRCS})

target_include_directories(lab PUBLIC ${INCS_DIR})
target_link_libraries(lab PRIVATE spdlog::spdlog)
