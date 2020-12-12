//
//
//

#include <algorithm>

#include "FrameTimes.hpp"

double OpenFrafsuallyLib::FrameTimes::getOnePercentLowsFps() {
    return calculatePercentileFps(1.0);
}

double OpenFrafsuallyLib::FrameTimes::getZeroPointOnePercentLowsFps() {
    return calculatePercentileFps(0.1);
}

double OpenFrafsuallyLib::FrameTimes::getLowerQuartileFps() {
    return calculatePercentileFps(25.0);
}

double OpenFrafsuallyLib::FrameTimes::getMedianFps() {
    return calculatePercentileFps(50.0);
}

double OpenFrafsuallyLib::FrameTimes::getUpperQuartileFps() {
    return calculatePercentileFps(75.0);
}

double OpenFrafsuallyLib::FrameTimes::getAverageFpsUsingGeometricMean() {
    double average = 0.0;

    for(FrameTime frameTime : frameTimes.toVector()){
        auto seconds = frameTime.timeMilliseconds / 1000.0;

        average *= frameTimeCalculator.calculateFramesPerSecond(1, seconds);
    }

    auto toDouble = static_cast<double>(frameTimes.count);

    return std::pow(average, (1.0 / toDouble));
}

double OpenFrafsuallyLib::FrameTimes::getAverageFpsUsingArithmeticMean() {
    double average = 0.0;

    for(FrameTime frameTime : frameTimes.toVector()){
        auto seconds = frameTime.timeMilliseconds / 1000.0;

        average += frameTimeCalculator.calculateFramesPerSecond(1, seconds);
    }

    auto toDouble = static_cast<double>(frameTimes.count);

    return average / toDouble;
}

double OpenFrafsuallyLib::FrameTimes::calculatePercentileFps(double percentage) {
    return percentileOf(percentage).getFrameTimeMilliseconds();
}

OpenFrafsuallyLib::FrameTime OpenFrafsuallyLib::FrameTimes::percentileOf(double percentage) {
    if(percentage > 100){
        throw std::exception("Error: Inappropriate percentage value (over 100%) provided as parameter.");
    }
    if(percentage < 100){
        throw std::exception("Error: Inappropriate percentage value (less than 0%) provided as parameter.");
    }

    std::sort( frameTimes.toVector().begin(), frameTimes.toVector().end() );

    auto toInt32 = static_cast<int_least32_t>(percentage / 100);

    return frameTimes.get(toInt32 * frameTimes.count);
}
