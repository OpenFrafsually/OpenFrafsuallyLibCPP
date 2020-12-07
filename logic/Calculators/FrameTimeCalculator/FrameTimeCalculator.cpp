//
//
//

#include "FrameTimeCalculator.hpp"

double AluminiumTech::FrafsuallyLib::FrameTimeCalculator::calculateSecondsPerFrame(double fps) {
    return (1.0 / fps);
}

double AluminiumTech::FrafsuallyLib::FrameTimeCalculator::calculateSecondsPerFrame(int64_t frames, double seconds) {
    auto framesConversion = static_cast<double>(frames);

    return seconds / framesConversion;
}

double AluminiumTech::FrafsuallyLib::FrameTimeCalculator::calculateFramesPerSecond(int64_t frames, double seconds) {
    auto framesConversion = static_cast<double>(frames);

    return framesConversion / seconds;
}

double AluminiumTech::FrafsuallyLib::FrameTimeCalculator::calculateFramesPerSecondWithFrameTimes(double frametimes,
                                                                                                 double seconds) {
   return ((seconds * 1000.0) / frametimes);
}

double AluminiumTech::FrafsuallyLib::FrameTimeCalculator::calculateFrameTimeMilliseconds(double fps) {
    return (1000.0 / fps);
}
