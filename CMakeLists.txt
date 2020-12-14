cmake_minimum_required(VERSION 3.17)
project(OpenFrafsuallyLib)

set(CMAKE_CXX_STANDARD 17)

add_library(cpp SHARED
        src/models/FrameTime/FrameTime.hpp

        src/Calculators/FrameTimeCalculator/FrameTimeCalculator.cpp
        src/Calculators/FrameTimeCalculator/FrameTimeCalculator.hpp

        src/models/FrameTimes/FrameTimes.hpp)

add_subdirectory(deps/developerkit/cpp)