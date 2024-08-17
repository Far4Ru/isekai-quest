#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#ifndef RENDERER_H
#define RENDERER_H

#include "window.hpp"
#include "engine/render_object/image_object.hpp"
#include "engine/render_object/text_object.hpp"
#include "engine/loader/loader.hpp"

class Renderer {
    public:
        Renderer();
        ~Renderer();

        void render();
        void start();
        void add(RenderObject* object);
        void remove(RenderObject* object);
        SDL_Renderer* get();

        Window* window;
    private:
        SDL_Renderer* renderer = NULL;
        std::vector<RenderObject*> render_queue;
};

#endif