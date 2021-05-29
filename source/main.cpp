#include "gamecontroller.cpp"
using namespace std;

int main() {
    GameController* gameController = new GameController();
    gameController->createCharacter(cin);
    return 0;
}