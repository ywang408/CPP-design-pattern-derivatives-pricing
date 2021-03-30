cmake_minimum_required(VERSION 3.17)
project(ch5_statistics_gatherer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ch5_statistics_gatherer
        ConvergenceTable.cpp
        ConvergenceTable.h
        MCStatistics.cpp
        MCStatistics.h
        Parameters.cpp
        Parameters.h
        PayOff3.cpp
        PayOff3.h
        PayOffBridge.cpp
        PayOffBridge.h
        Random1.cpp
        Random1.h
        SimpleMC7.cpp
        SimpleMC7.h
#        StatsMain1.cpp
        Vanilla3.cpp
        Vanilla3.h
        Wrapper.h StatsMain2.cpp)
