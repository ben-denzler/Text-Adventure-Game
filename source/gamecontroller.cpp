#include "../header/game_controller.hpp"
#include "../header/factory.hpp"
#include <iostream>
#include <string>

using namespace std;

void GameController::createCharacter() {
    string name;
    int type;

    // Ask for user input
    cout << "Please type the name of your character. Press Enter to continue." << endl;
    getline(cin, name);

    // Display description of classes
    cout << "Choose the corresponding number of your class." << endl;
    cout << "1) Rougemouse - a fast mouse who specializes in small weaponary." << endl;
    cout << "2) Swordmouse - a gallant mouse who specializes in sword combat." << endl;
    cout << "3) Monkmouse - a wise mouse who specializes in using words and staffs." << endl;

    // Handle invalid input for type
    cin >> type;
    while ((type != 1) && (type != 2) && (type != 3)) {
        cout << "Invalid input, try again." << endl;
        cin >> type;
    }

    // Create character from factory
    AbstractFactory* my_factory = new EntityFactory();
    currCharacter = my_factory->createCharacter(name, type);

    // Confirms that the name and type is correct
    cout << currCharacter->getName() + " is a " + currCharacter->getType() << "!" << endl;

    // Delete anything created down here :)
    delete my_factory;
}

void GameController::createEnemies() {
    AbstractFactory* my_factory = new EntityFactory();
    
    // 3,2,1
    enemiesInGame.push_back(my_factory->createEnemy(3));
    enemiesInGame.push_back(my_factory->createEnemy(2));
    enemiesInGame.push_back(my_factory->createEnemy(1));
}

std::string GameController::getNarrative(std::string fileName) {
    
   // get next line
   //if line is CHOICE
   //getnext two times 
    
}

// Returns 0 if enemy is dead
// Returns 1 if character is dead
// Returns 3 if character wants to flee.
int GameController::battle() {
    //get enemy from narrative
    currEnemy = enemiesInGame.pop_back();

    if (currEnemy != nullptr) {
        cout << "BATTLE HAS STARTED! " << currEnemy->getName() << " is attacking you." << endl;
        while (!currCharacter->isDead() && !currEnemy->isDead()) {
            
            // Display stats and options
            cout << "Character stats:" << currCharacter->display() << endl;
            cout << "Enemy stats: " << currEnemy->display() << endl;
            battleChoice = displayBattleOptions();

            // Attack
            if (battleChoice == 1) {
                currEnemy->takeDamage(currCharacter->getAttack());
                cout << "You dealt " << 
            }

            // Defend
            else if (battleChoice == 2) {
                currCharacter->takeDamage(currEnemy->getAttack() - currCharacter->getDefense());
            }

            // Flee
            else if (battleChoice == 3) {
                cout << "You were able to safely get away." << endl;
                return 3;
            }

            else if (battleChoice == 4) {
                // Access Inventory
                currCharacter->getInventory()->display();
                //currCharacter->use(currCharacter->getInventory()->find(string))
                
            }

            // Enemy's turn
            cout << currEnemy->getName() << " attacks!" << endl;
            currCharacter->takeDamage(currEnemy->getAttack());
            cout << "Player losses "  << currEnemy->getAttack() << " HP" << endl;
        }
        
        if (currEnemy->isDead()) {
            cout << "Congratulations! " << currEnemy->getName() << " has fainted." << endl;
            delete currEnemy;
            return 0;
        }
        else if (currCharacter->isDead()) {
            cout << "You have passed out. Can you find the strength to save the world again?" << endl;
            return 1;
        }
    }
    else {
        cout << "ERROR: NO ENEMY TO FIGHT" << endl;
    }
}

int GameController::displayBattleOptions(){
    int num = 0;
    
    cout << "Choose one of the options below:" << endl;
    cout << "1) ATTACK" << endl;
    cout << "2) DEFEND" << endl;
    cout << "3) FLEE" << endl;
    cout << "4) Access Inventory" << endl;
    
    cin >> num;
    while ((num != 1) && (num != 2) && (num != 3) && (num != 4)) {
        cout << "Invalid input, try again." << endl;
        cin >> num;
    }
    
    return num;
}
