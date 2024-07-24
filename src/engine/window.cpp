#include "engine/window.hpp"

Window::Window() {
    //
}

Window::~Window() {
    SDL_DestroyWindow(this->window);
}

int Window::create() {
    this->window = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (this->window == NULL) {
        std::cout << SDL_ERROR << SDL_GetError() << std::endl;
        return 1;
    }
    return 0;
}

SDL_Window* Window::get() {
    return this->window;
}
