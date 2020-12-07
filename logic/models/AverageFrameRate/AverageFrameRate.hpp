//
//
//

#ifndef FRAFSUALLYLIB_AVERAGEFRAMERATE_HPP
#define FRAFSUALLYLIB_AVERAGEFRAMERATE_HPP

#include "../FrameTime/FrameTime.hpp"

using namespace std;

namespace AluminiumTech::FrafsuallyLib{
    class AverageFrameRate {

        public:
            AluminiumTech::DeveloperKit::ObjectList<FrameTime> frametimes;

            int64_t getNumberOfFrames();


        protected:


    };
}


#endif //FRAFSUALLYLIB_AVERAGEFRAMERATE_HPP
