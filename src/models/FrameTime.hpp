//
//
//

#ifndef CPP_FRAMETIME_HPP
#define CPP_FRAMETIME_HPP

#include <cmath>

#include "../Calculators/FrameTimeCalculator/FrameTimeCalculator.hpp"

using namespace std;

namespace OpenFrafsuallyLib{
    /**
     *
     */
    class FrameTime {

    public:
        int_least32_t frameNumber;

        double startTimeMilliseconds;
        double endTimeMilliseconds;

        FrameTime(){
            frameNumber = 0;

            startTimeMilliseconds = 0.0;
            endTimeMilliseconds = 0.0;
        }

        double getTimeMilliseconds(){
           return std::abs(startTimeMilliseconds - endTimeMilliseconds);
        }

        double getFrameTimeMilliseconds(){
            double conversion = (getTimeMilliseconds() / 1000.0);

            double fps = frameTimeCalculator.calculateFramesPerSecond(1, conversion / 1000.0);

            return frameTimeCalculator.calculateFrameTimeMilliseconds(fps);
        }


    protected:
        FrameTimeCalculator frameTimeCalculator;

    };
}


#endif //CPP_FRAMETIME_HPP
