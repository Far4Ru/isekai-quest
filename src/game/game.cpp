#include "game/game.hpp"

Game::Game() {
    SDL_Event windowEvent;
    while (true) {
        if (SDL_PollEvent(&windowEvent)) {
            switch (windowEvent.type) {
                case SDL_QUIT:
                    return;
            }
        }
    }
}