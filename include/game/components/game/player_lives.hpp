#include "game/components/game/player_life.hpp"

#define MAX_PLAYER_LIVES 3

class PlayerLives {
    public:
        PlayerLives();
        ~PlayerLives();

        void add(PlayerLife* life);
        void remove(PlayerLife* life);
        void reduce();
    private:
        int count = MAX_PLAYER_LIVES;
        std::vector<PlayerLife*> lives;
};