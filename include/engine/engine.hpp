#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "engine/renderer.hpp"

class Engine {
    public:
        Engine();
        ~Engine();

        void start();
    private:
        Renderer* renderer = NULL;
        int init();
        void close();
};