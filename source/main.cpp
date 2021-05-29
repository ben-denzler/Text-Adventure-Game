#include "gamecontroller.cpp"
#include <fstream>

int main() {
    ifstream inFS;

    inFS.open("script.txt");
    if (!inFS.is_open()) {
        cout << "Sorry, bad file." << endl;
        exit(0);
    }

    GameController* gameController = new GameController();
    gameController->createCharacter(cin);
    gameController->createEnemies();

    int gameStatus = gameController->getNarrative(inFS, cin);
    while (gameStatus != -1) {
        gameStatus = gameController->getNarrative(inFS, cin);
    }
    return 0;
}