cmake_minimum_required(VERSION 3.17)
project(FrafsuallyLib)

set(CMAKE_CXX_STANDARD 20)

add_library(cpp SHARED
        logic/models/FrameTime/FrameTime.cpp
        logic/models/FrameTime/FrameTime.hpp

        logic/Calculators/FrameTimeCalculator/FrameTimeCalculator.cpp
        logic/Calculators/FrameTimeCalculator/FrameTimeCalculator.hpp

        logic/models/AverageFrameRate/AverageFrameRate.cpp
        logic/models/AverageFrameRate/AverageFrameRate.hpp

        logic/Calculators/AverageFrameRateCalculator/AverageFrameRateCalculator.cpp
        logic/Calculators/AverageFrameRateCalculator/AverageFrameRateCalculator.hpp)