#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <algorithm>

#ifndef RENDERER_H
#define RENDERER_H

#include "window.hpp"
#include "engine/entity/render_object/image_object.hpp"
#include "engine/entity/render_object/text_object.hpp"
#include "engine/loader/loader.hpp"

class Renderer {
    public:
        Renderer();
        ~Renderer();

        void render();
        void start();
        void add(RenderObject* object);
        void add_next(RenderObject* object);
        void remove(RenderObject* object);
        SDL_Renderer* get();
        void setScale(float scale);
        void clear();

        Window* window;
    private:
        bool active = false;
        SDL_Renderer* renderer = NULL;
        std::vector<RenderObject*> next_render_queue;
        std::vector<RenderObject*> render_queue;
};

#endif