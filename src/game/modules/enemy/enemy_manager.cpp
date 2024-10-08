#include "game/game.hpp"

EnemyManager::EnemyManager() {
    timer.start();
    std::srand(std::time(nullptr));
    TimeObject* time = engine->add->time();
    auto timeFunc = [&]() {
        int ticks = timer.get_ticks();
        if (ticks > 100 * (1000 / 60)) {
            int level = (game->gameScene->game_time_text->game_seconds * 5) / 60;
            int enemy_number = rand() % (1 + level) + 1;
            int side = std::rand() / ((RAND_MAX + 1u) / 4);
            int x = 0, y = 0;
            int width = 1920, height = 1080, padding = 100;
            switch (side) {
                case 0:
                    x = std::rand() / ((RAND_MAX + 1u) / width);
                    y =  -(std::rand() / ((RAND_MAX + 1u) / padding));
                    break;
                case 1:
                    x = width + (std::rand() / ((RAND_MAX + 1u) / padding));
                    y = std::rand() / ((RAND_MAX + 1u) / height);
                    break;
                case 2:
                    x = std::rand() / ((RAND_MAX + 1u) / width);
                    y = height + std::rand() / ((RAND_MAX + 1u) / padding);
                    break;
                case 3:
                    x =  -(std::rand() / ((RAND_MAX + 1u) / padding));
                    y = std::rand() / ((RAND_MAX + 1u) / height);
                    break;
            }
            std::string enemy_prefix = "candy_";
            std::string enemy_name = enemy_prefix + std::to_string(enemy_number);
            Enemy* enemy = new Enemy(x, y, enemy_name);
            add(enemy);
            timer.start();
        }
    };
    time->setProcess(timeFunc);
}

EnemyManager::~EnemyManager() {
    timer.stop();
    killAll();
}

void EnemyManager::add(Enemy* enemy) {
    enemies.push_back(enemy);
}

void EnemyManager::remove(Enemy* enemy) {
    enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
}

void EnemyManager::kill(Enemy* enemy) {
    remove(enemy);
    enemy->destroy();
}

void EnemyManager::killAll() {
    for (Enemy* enemy : enemies) {
        enemy->destroy();
    }
    std::vector<Enemy*>().swap(enemies);
}
