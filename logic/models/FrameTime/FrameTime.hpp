//
//
//

#ifndef CPP_FRAMETIME_HPP
#define CPP_FRAMETIME_HPP

#include <cmath>
#include <iostream>

#include "../../Calculators/FrameTimeCalculator/FrameTimeCalculator.hpp"

using namespace std;

namespace AluminiumTech::FrafsuallyLib{
    class FrameTime {

    public:
        int_least64_t frameNumber;

        double startTimeMilliseconds;
        double endTimeMilliseconds;

        double timeMilliseconds = abs(startTimeMilliseconds - endTimeMilliseconds);

        double getFrameTimeMilliseconds();


    protected:
        FrameTimeCalculator frameTimeCalculator;

    private:


    };
}


#endif //CPP_FRAMETIME_HPP
