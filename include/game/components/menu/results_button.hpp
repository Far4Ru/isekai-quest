#ifndef RESULTS_BUTTON_H
#define RESULTS_BUTTON_H

#include "engine/engine.hpp"

class ResultsButton {
    public:
        ResultsButton();
        ~ResultsButton();

        bool pressed = false;
    private:
        TextObject* text;
};

#endif
