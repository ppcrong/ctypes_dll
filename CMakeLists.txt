cmake_minimum_required(VERSION 3.10)
project(ctypes_dll VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -g3")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif ()
message(STATUS "CMAKE_BUILD_TYPE: [${CMAKE_BUILD_TYPE}]")

set(lib ${PROJECT_NAME})
file(GLOB SRC *.c)
add_library(${lib} SHARED ${SRC})

target_include_directories(${lib} PUBLIC
  include
  ${CMAKE_CURRENT_LIST_DIR}/include
  )
