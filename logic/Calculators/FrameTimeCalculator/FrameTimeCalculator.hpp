//
//
//

#ifndef CPP_FRAMETIMECALCULATOR_HPP
#define CPP_FRAMETIMECALCULATOR_HPP


#include <iostream>

namespace AluminiumTech::FrafsuallyLib{

    class FrameTimeCalculator {

    public:
        double calculateSecondsPerFrame(double fps);
        double calculateSecondsPerFrame(int64_t frames, double seconds);

        double calculateFramesPerSecond(int64_t frames, double seconds);

        double calculateFramesPerSecondWithFrameTimes(double frametimes, double seconds);

        double calculateFrameTimeMilliseconds(double fps);

    protected:

    };
}


#endif //CPP_FRAMETIMECALCULATOR_HPP
