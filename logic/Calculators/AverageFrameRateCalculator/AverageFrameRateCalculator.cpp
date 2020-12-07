//
//
//

#include "AverageFrameRateCalculator.hpp"

double AluminiumTech::FrafsuallyLib::AverageFrameRateCalculator::GetAverageFpsUsingGeometricMean(
        AluminiumTech::FrafsuallyLib::FrameTime* frametimes) {
    double average = 0.0;

    for(int index = 0; index < sizeof(frametimes)/sizeof(frametimes[0]); index++){
        auto seconds = frametimes[index].timeMilliseconds / 1000.0;

        average *= frameTimeCalculator.calculateFramesPerSecond(1, seconds);
    }

   return pow(average, (1.0 / static_cast<double>(sizeof(frametimes)/sizeof(frametimes[0]))));
}

double AluminiumTech::FrafsuallyLib::AverageFrameRateCalculator::GetAverageFpsUsingArithmeticMean(
        AluminiumTech::FrafsuallyLib::FrameTime* frametimes) {
    double average = 0.0;

    for(int index = 0; index < sizeof(frametimes)/sizeof(frametimes[0]); index++){
        auto seconds = frametimes[index].timeMilliseconds / 1000.0;

        average += frameTimeCalculator.calculateFramesPerSecond(1, seconds);
    }

    return average / static_cast<double>(sizeof(frametimes)/sizeof(frametimes[0]));
}

double AluminiumTech::FrafsuallyLib::AverageFrameRateCalculator::CalculatePercentile(double percentage, FrameTime* frametimes) {

    if(!(percentage >= 0 && percentage <= 1.0) || (percentage >= 0 && percentage <= 100)){
        percentage = percentage / 100;
    }
    else if(percentage / 100 < 0){
        percentage = percentage * 100;
    }
    else{

    }

    auto percentileIndex = static_cast<int_least32_t>((percentage / 100.0) * sizeof(frametimes)/sizeof(frametimes[0]));

    return frametimes[percentileIndex].timeMilliseconds;
}
