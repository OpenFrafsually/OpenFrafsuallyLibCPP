//
//
//

#include "FrameTimeCalculator.hpp"

double OpenFrafsuallyLib::FrameTimeCalculator::calculateSecondsPerFrame(double fps) {
    return (1.0 / fps);
}

double OpenFrafsuallyLib::FrameTimeCalculator::calculateSecondsPerFrame(int_least32_t frames, double seconds) {
    auto framesConversion = static_cast<double>(frames);

    return seconds / framesConversion;
}

double OpenFrafsuallyLib::FrameTimeCalculator::calculateFramesPerSecond(int_least32_t frames, double seconds) {
    auto framesConversion = static_cast<double>(frames);

    return framesConversion / seconds;
}

double OpenFrafsuallyLib::FrameTimeCalculator::calculateFramesPerSecondWithFrameTimes(double frametimes,
                                                                                                 double seconds) {
   return ((seconds * 1000.0) / frametimes);
}

double OpenFrafsuallyLib::FrameTimeCalculator::calculateFrameTimeMilliseconds(double fps) {
    return (1000.0 / fps);
}
