//
// Created by Severin on 22.02.2023.
//

#ifndef BUILDANDPROGRAMM_EANIMATION_H
#define BUILDANDPROGRAMM_EANIMATION_H

#include <raylib.h>

namespace Engine {

    template<typename T>
    class EAnimation {
    public:
        EAnimation() = default;

        explicit EAnimation(T* parameter) : parameter(parameter){
        }

        void Step(){
            *parameter = startValue + (endValue - startValue) * (float) (currentFrame - startFrame) / (endFrame - startFrame);
            currentFrame++;
        }

        void Start(T start, T end, int frames){
            startValue = start;
            endValue = end;
            endFrame = frames;
            currentFrame = 0;
            startFrame = 0;
            Step();
        }

        bool Ended(){
            return currentFrame > endFrame;
        }

        bool Started(){
            return currentFrame > startFrame;
        }

        T startValue;
        T endValue;
        bool started = false;

        int endFrame = 0;
        int startFrame = 0;
        int currentFrame = 0;
    private:
        T* parameter = nullptr;
    };

} // Engine

#endif //BUILDANDPROGRAMM_EANIMATION_H
