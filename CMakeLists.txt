cmake_minimum_required(VERSION 3.17)
project(OpenFrafsuallyLib VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_library(OpenFrafsuallyLib SHARED
        src/models/FrameTime.hpp

        src/Calculators/FrameTimeCalculator/FrameTimeCalculator.cpp
        src/Calculators/FrameTimeCalculator/FrameTimeCalculator.hpp

        src/models/FrameTimes.hpp)

add_subdirectory(deps/developerkit/cpp)

export(TARGETS OpenFrafsuallyLib
        NAMESPACE ${PACKAGE_NAME}::
        FILE OpenFrafsuallyLib.cmake)