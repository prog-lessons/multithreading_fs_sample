cmake_minimum_required(VERSION 3.0.0)
project(lesson_01_threads VERSION 0.1.0)

#include(CTest)
#enable_testing()

find_package(Threads REQUIRED)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -stdlib=libc++")
add_executable(lesson.exe main.cpp dirmgr.cpp)
target_link_libraries(lesson.exe c++fs ${CMAKE_THREAD_LIBS_INIT})

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
