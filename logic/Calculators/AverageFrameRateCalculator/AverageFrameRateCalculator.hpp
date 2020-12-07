//
//
//

#ifndef FRAFSUALLYLIB_AVERAGEFRAMERATECALCULATOR_HPP
#define FRAFSUALLYLIB_AVERAGEFRAMERATECALCULATOR_HPP


#include "../../models/FrameTime/FrameTime.hpp"

namespace AluminiumTech::FrafsuallyLib{
    class AverageFrameRateCalculator {

    public:
        double GetAverageFpsUsingGeometricMean(FrameTime frametimes[]);

        double GetAverageFpsUsingArithmeticMean(FrameTime frametimes[]);

        double CalculatePercentile(double percentage, FrameTime frametimes[]);

    protected:
        FrameTimeCalculator frameTimeCalculator;


    };
}


#endif //FRAFSUALLYLIB_AVERAGEFRAMERATECALCULATOR_HPP
