//
//
//

#ifndef FRAFSUALLYLIB_FRAMETIMES_HPP
#define FRAFSUALLYLIB_FRAMETIMES_HPP

#include <algorithm>

#include "../FrameTime/FrameTime.hpp"

#include "../../../developerkit/cpp/src/Types/Lists/ObjectList.hpp"

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

        double getOnePercentLowsFps(){
            return calculatePercentileFps(1.0);
        }

        double getZeroPointOnePercentLowsFps(){
            return calculatePercentileFps(0.1);
        }

        double getLowerQuartileFps(){
            return calculatePercentileFps(25.0);
        }

        double getMedianFps(){
            return calculatePercentileFps(50.0);
        }

        double getUpperQuartileFps(){
            return calculatePercentileFps(75.0);
        }

        double getAverageFpsUsingGeometricMean(){
            double average = 0.0;

            for(FrameTime frameTime : frameTimes.toVector()){
                auto seconds = frameTime.getTimeMilliseconds() / 1000.0;

                average *= frameTimeCalculator.calculateFramesPerSecond(1, seconds);
            }

            auto toDouble = static_cast<double>(frameTimes.count);

            return std::pow(average, (1.0 / toDouble));
        }

        double getAverageFpsUsingArithmeticMean(){
            double average = 0.0;

            for(FrameTime frameTime : frameTimes.toVector()){
                auto seconds = frameTime.getTimeMilliseconds() / 1000.0;

                average += frameTimeCalculator.calculateFramesPerSecond(1, seconds);
            }

            auto toDouble = static_cast<double>(frameTimes.count);

            return average / toDouble;
        }

        double calculatePercentileFps(double percentage){
            return percentileOf(percentage).getFrameTimeMilliseconds();
        }

        FrameTime percentileOf(double percentage){
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

    protected:
        FrameTimeCalculator frameTimeCalculator;
    };
}


#endif //FRAFSUALLYLIB_FRAMETIMES_HPP
