//
//
//

#include "FrameTime.hpp"

double OpenFrafsuallyLib::FrameTime::getFrameTimeMilliseconds() {
    double conversion = (timeMilliseconds / 1000.0);

    double fps = frameTimeCalculator.calculateFramesPerSecond(1, conversion / 1000.0);

    return frameTimeCalculator.calculateFrameTimeMilliseconds(fps);
}