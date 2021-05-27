#include "gamecontroller.cpp"
using namespace std;

int main() {
    GameController* gameController = new GameController();
    string item;
    gameController->createCharacter(cin);
    cout << "----------------------------------------------------" << endl;
    cout << "INVENTORY: Armor, Weapons & Consumables" << endl;
    gameController->getCurrCharacter()->getInventory()->display();
    cout << "----------------------------------------------------" << endl;
    cout << "Choose your item by typing its name (Case Matters). Press Enter to continue." << endl;
    getline(cin, item);
    cout << "You have chosen: " << item << endl;
    return 0;
}