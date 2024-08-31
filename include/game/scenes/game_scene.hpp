#include "engine/engine.hpp"
#include "game/components/game/background.hpp"
#include "game/modules/player/player.hpp"
#include "game/modules/sound/sound.hpp"
#include "game/components/game/fps_text.hpp"
#include "game/components/game/mouse_text.hpp"
#include "game/components/game/screen_text.hpp"
#include "game/modules/bullet/bullet_manager.hpp"
#include "game/modules/enemy/enemy_manager.hpp"

class GameScene {
    public:
        GameScene();

        void clear();
        void start();

        Background* background;
        Player* player;
        Sound* sound;
        BulletManager* bullet_manager;
        EnemyManager* enemy_manager;
        FPSText* fps_text;
        MouseText* mouse_text;
        ScreenText* screen_text;
    private:
        bool active = false;
};
