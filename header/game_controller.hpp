#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include "baseItem.hpp"
#include <vector>

using namespace std;

class GameController {
    private:
        vector<Entity*> enemiesInGame;
        Entity* currCharacter = nullptr;
        Entity* currEnemy = nullptr;

    public:
        void createCharacter();
        void createEnemies();
        std::string getNarrative(std::string);
        int battle();
        int displayBattleOptions();
};

#endif