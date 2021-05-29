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
    cout << "Press the ENTER key to continue through the story." << endl;
    cout << "Game has started." << endl << endl;
    gameController->createCharacter(cin);
    gameController->createEnemies();

    char input;
    int gameStatus = gameController->getNarrative(inFS, cin);

    while ((gameStatus != -1)) {
        cin.get(input);
        while (input != '\n') { cin.get(input); }
        cout << endl;
        gameStatus = gameController->getNarrative(inFS, cin);
    }
    return 0;
}   