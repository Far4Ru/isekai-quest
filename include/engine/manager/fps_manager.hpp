#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>

#include "engine/utils/timer.hpp"

class FPS {
    public:
        FPS();

        std::string get();
        void start();
        void end();
    private:
        std::string value = "";
        Timer fpsTimer;
        Timer capTimer;
        int countedFrames = 0;
};
