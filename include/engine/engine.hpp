#pragma once

#include <SDL2/SDL.h>

#include "window.hpp"
#include "renderer.hpp"

class Engine {
    public:
        Engine();
        ~Engine();

        Renderer* renderer;
        Window* window;
    private:
        int init();
};