#include "engine/engine.hpp"
#include "game/modules/bullet/bullet.hpp"

class BulletManager {
    public:
        BulletManager();
    private:
        std::vector<Bullet*> bullets;
        Timer timer;
};