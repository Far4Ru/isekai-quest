#ifndef PLAY_BUTTON_H
#define PLAY_BUTTON_H

#include "engine/engine.hpp"

class PlayButton {
    public:
        PlayButton();
        ~PlayButton();
        
        bool pressed = false;
    private:
        TextObject* text;
};

#endif
