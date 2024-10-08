#include "game/game.hpp"

GameTimeText::GameTimeText() {
    text = engine->add->text("Airfool");
    text->x = WIDTH / 2 - 70;
    text->y = 0;
    timer.start();
    auto timeFunc = [&]() {
        int ticks = timer.get_ticks();
        if (ticks > 1000 ) {
            game_seconds++;
            text->setText(getTime());
            timer.start();
        }
    };
    text->setProcess(timeFunc);
}

GameTimeText::~GameTimeText() {
    timer.stop();
    text->destroy();
}

std::string GameTimeText::getTime() {
    int game_seconds_display = GAME_DURATION - game_seconds;
    std::string seconds = std::to_string(game_seconds_display % 60);
    std::string minutes = std::to_string(game_seconds_display / 60);
    return (minutes.length() > 1 ? "" : "0") + minutes + ":" + (seconds.length() > 1 ? "" : "0") + seconds;
}
