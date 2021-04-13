cmake_minimum_required(VERSION 3.17)
project(ClionProject)

set(CMAKE_CXX_STANDARD 14)
set (Boost_USE_STATIC_LIBS On)
find_package(Boost 1.75 COMPONENTS random)
FILE(GLOB MyCSources *.cpp *.h)
ADD_EXECUTABLE(MyExecutable ${MyCSources} Random3.h Random3.cpp)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(MyExecutable ${Boost_LIBRARIES})
endif()

