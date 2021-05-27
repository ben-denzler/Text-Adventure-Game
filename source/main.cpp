#include "gamecontroller.cpp"
using namespace std;

int main() {
    GameController* gameController = new GameController();
    gameController->createCharacter(cin);
    gameController->createCharacter(cin);
    gameController->createCharacter(cin);
    return 0;
}