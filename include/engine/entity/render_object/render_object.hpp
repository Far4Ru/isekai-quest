#include <SDL2/SDL.h>
#include <iostream>
#include <functional>

#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

class RenderObject {
    public:
        virtual void render(SDL_Renderer* renderer) = 0;
        virtual void process() = 0;
        virtual void destroy() = 0;
        virtual ~RenderObject() = default;
        virtual void setScale(float scale) = 0;

        std::string name = "";
        bool active = true;
        bool to_destroy = false;
};

#endif