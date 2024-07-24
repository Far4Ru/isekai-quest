#include "engine/engine.hpp"


Engine::Engine() {
    int isInited = this->init();
    int isWindowCreated = this->window->create();
    int isWRendererCreated = this->renderer->create(this->window);
}

int Engine::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    return 0;
}

Engine::~Engine() {
    this->window->~Window();
    this->renderer->~Renderer();
    SDL_Quit();
}