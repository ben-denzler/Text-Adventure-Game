#include "../header/game_controller.hpp"
using namespace std;

int main() {
    GameController* gameController = new GameController();
    gameController->createCharacter();
    delete gameController;
    return 0;
}