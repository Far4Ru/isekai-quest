#include "game/sound.hpp"

Sound::Sound() {
    engine->sound->playMusic("PositiveEnergy");
    engine->keyboard->add(SDL_SCANCODE_SPACE, [&]() {
        engine->sound->playSound("BubbleSpell");
    });
    engine->keyboard->add(SDL_SCANCODE_1, [&]() {
        engine->sound->pauseMusic();
    });
    engine->keyboard->add(SDL_SCANCODE_2, [&]() {
        engine->sound->resumeMusic();
    });
}
