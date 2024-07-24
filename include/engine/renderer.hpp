#include <SDL2/SDL.h>
#include "engine/window.hpp"

class Renderer {
    public:
        Renderer();
        ~Renderer();
        int create(Window *window);
        void clear();
    private:
        SDL_Renderer *renderer;
};
