//
//
//

#ifndef FRAFSUALLYLIB_FRAMETIMES_HPP
#define FRAFSUALLYLIB_FRAMETIMES_HPP

#include "../FrameTime/FrameTime.hpp"

#include "../../../developerkit/cpp/Types/Lists/ObjectList/ObjectList.hpp"

namespace OpenFrafsuallyLib{
    /**
     *
     */
    class FrameTimes {

    public:
        AluminiumTech::DeveloperKit::ObjectList<FrameTime> frameTimes;

        int_least32_t numberOfFrames(){
            frameTimes.count;
        }

        double getOnePercentLowsFps();
        double getZeroPointOnePercentLowsFps();

        double getLowerQuartileFps();
        double getMedianFps();
        double getUpperQuartileFps();

        double getAverageFpsUsingGeometricMean();
        double getAverageFpsUsingArithmeticMean();

        double calculatePercentileFps(double percentage);

        FrameTime percentileOf(double percentage);

    protected:
        FrameTimeCalculator frameTimeCalculator;
    };
}


#endif //FRAFSUALLYLIB_FRAMETIMES_HPP
