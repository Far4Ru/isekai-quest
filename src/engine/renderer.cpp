#include "engine/renderer.hpp"

Renderer::Renderer() {
}
Renderer::~Renderer() {
    SDL_DestroyRenderer(this->renderer);
}

void Renderer::clear() {
    SDL_RenderClear(this->renderer);
}

int Renderer::create(Window *window) {
    this->renderer = SDL_CreateRenderer(window->get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->renderer == NULL){
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
    return 0;
}