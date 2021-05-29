#ifndef GAME_CONTROLLER_CPP
#define GAME_CONTROLLER_CPP

#include "../header/game_controller.hpp"
#include "../header/factory.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <ios>
#include <limits>

void GameController::createCharacter(istream& input) {
    string name;
    char type;

    // Ask for user input
    cout << "Please type the name of your character. Press Enter to continue." << endl;
    getline(input, name);

    // Display description of classes
    cout << endl;
    cout << "Choose the corresponding number of your class." << endl;
    cout << "1) Rougemouse - a fast mouse who specializes in small weaponary." << endl;
    cout << "2) Swordmouse - a gallant mouse who specializes in sword combat." << endl;
    cout << "3) Monkmouse - a wise mouse who specializes in using words and staffs." << endl;

    // Handle invalid input for type
    input >> type;
    while (!isdigit(type) || ((type != '1') && (type != '2') && (type != '3'))) {
        cout << "Invalid input, try again." << endl;
        input >> type;
    }
    cout << endl;

    // Create character from factory
    AbstractFactory* my_factory = new EntityFactory();
    currCharacter = my_factory->createCharacter(name, atoi(&type));

    // Confirms that the name and type is correct
    cout << endl;
    cout << currCharacter->getName() + " is a " + currCharacter->getType() << "!" << endl << endl;

    // Delete anything created down here :)
    input.ignore(numeric_limits<streamsize>::max(), '\n');
    delete my_factory;
}

void GameController::createEnemies() {
    AbstractFactory* my_factory = new EntityFactory();
    
    // 3,2,1
    enemiesInGame.push_back(my_factory->createEnemy(3));
    enemiesInGame.push_back(my_factory->createEnemy(2));
    enemiesInGame.push_back(my_factory->createEnemy(1));

    // Delete anything created down here :)
    delete my_factory;
}

int GameController::getNarrative(istream& script, istream& playerInput) {
    string nextLine;
    string choiceDialogue, choice1, choice2, result1, result2;
    
    getline(script, nextLine);

    if (nextLine == "END") {
        cout << "You have finished the game! Congrats!" << endl;
        cout << "Press any key to exit." << endl;
        char temp;
        playerInput >> temp;
        return -1;
    }
    else if (nextLine == "BATTLE") {
        return battle(playerInput);
    }
    else if (nextLine == "CHOICE") {
        char playerChoice = 0;
        getline(script, choiceDialogue);             // PROMPT: Girl is in trouble
        getline(script, choice1);                    // Option 1: 1) Save her
        getline(script, choice2);                    // Option 2: 2) Ignore her
        getline(script, result1);                    // Result 1: You were rewarded with a kiss. You stroll off happily
        getline(script, result2);                    // Result 2: You hurridly walked away, ashamed of your decision
        
        cout << choiceDialogue << endl << endl;
        cout << "1) " << choice1 << endl;
        cout << "2) " << choice2 << endl << endl;
        cout << "Make a choice by typing 1 or 2..." << endl;

        playerInput >> playerChoice;
        while (!isdigit(playerChoice) || ((playerChoice != '1') && (playerChoice != '2'))) {
            cout << "Invalid input, try again." << endl;
            playerInput >> playerChoice;
        }
        cout << endl;

        if (playerChoice == '1') {
            // baseItem* newItem = new Consumable("Cheese", )
            // currCharacter->getInventory()->addItem();
            cout << result1 << endl; 
        }
        else { cout << result2 << endl; }
        cout << endl;

        playerInput.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else { std::cout << nextLine << std::endl; }
    return 0;
}

// Returns 1 if character is dead
// Returns 2 if enemy does not exist
// Returns 3 if character wants to flee.
// Returns 4 if enemy is dead
int GameController::battle(istream& inFS) {
    // Get enemy from back of list
    currEnemy = enemiesInGame.back();
    enemiesInGame.pop_back();

    if (currEnemy != nullptr) {
        cout << "BATTLE HAS STARTED! " << currEnemy->getName() << " is attacking you." << endl << endl;
        while (!currCharacter->isDead() && !currEnemy->isDead()) {
            
            // Display stats and options
            currCharacter->display();
            currEnemy->display(); cout << endl;

            int battleChoice = displayBattleOptions(inFS);
            if (battleChoice == 3) {
                cout << "You were able to safely get away." << endl;
                return 0; // NECESSARY DONT DELETE
            }
            else { evalBattleChoice(battleChoice, inFS); }
        }
        return finishBattle(inFS);
    }
    else {
        cout << "ERROR: NO ENEMY TO FIGHT" << endl;
    }
    return 0;
}

int GameController::displayBattleOptions(istream& input){
    char num;
    
    cout << "Choose one of the options below:" << endl;
    cout << "1) ATTACK" << endl;
    cout << "2) DEFEND" << endl;
    cout << "3) FLEE" << endl;
    cout << "4) ACCESS INVENTORY" << endl;
    
    input >> num;
    while (!isdigit(num) || ((num != '1') && (num != '2') && (num != '3') && (num != '4'))) {
        cout << "Invalid input, try again." << endl;
        input >> num;
    }
    cout << endl;

    input.ignore(numeric_limits<streamsize>::max(), '\n');
    return atoi(&num);
}

// Helper for battle()
void GameController::evalBattleChoice(int battleChoice, istream& inFS) {
    // Attack
    if (battleChoice == 1) {
        currEnemy->takeDamage(currCharacter->getAttack());
        cout << "You dealt " << currCharacter->getAttack() << " damage!" << endl;
    }

    // Defend
    else if (battleChoice == 2) {
        cout << "You chose to defend." << endl;
        cout << currEnemy->getName() << " attacks!" << endl;
        currCharacter->takeDamage(currEnemy->getAttack() - currCharacter->getDefense());
        cout << "Player loses "  << (currEnemy->getAttack() - currCharacter->getDefense()) << " HP." << endl << endl;
    }

    // Access Inventory and change weapon, armor, or use consumable
    else if (battleChoice == 4) {
        cout << "----------------------------------------------------" << endl;
        cout << "INVENTORY: Armor, Weapons & Consumables" << endl;
        currCharacter->getInventory()->display();
        cout << "----------------------------------------------------" << endl;
        cout << "Choose your item by typing its name (Case Matters). Press Enter to continue." << endl;
        
        string item;
        getline(inFS, item);
        baseItem* foundItem = currCharacter->getInventory()->find(item);
        while (foundItem == nullptr) {
            cout << "ERROR: ITEM NOT FOUND. Please type the item's name again." << endl;
            getline(inFS, item);
            foundItem = currCharacter->getInventory()->find(item);
        }
        foundItem->use(currCharacter);
        if (dynamic_cast<Consumable*>(foundItem) != nullptr) { currCharacter->getInventory()->removeItem(foundItem); }
    }

    if ((battleChoice != 2) && (currEnemy != nullptr) && (!currEnemy->isDead())) {
        // Enemy's turn
        cout << currEnemy->getName() << " attacks!" << endl;
        currCharacter->takeDamage(currEnemy->getAttack());
        cout << "Player loses "  << currEnemy->getAttack() << " HP!" << endl;
    }
}

// Helper for battle()
int GameController::finishBattle(istream& inFS) {
    if (currEnemy->isDead()) {
        cout << "Congratulations! " << currEnemy->getName() << " has fainted." << endl << endl;
        delete currEnemy;
    }
    else if (currCharacter->isDead()) {
        cout << "You have passed out. Can you find the strength to save the world again?" << endl;
        cout << "Press any key to exit." << endl;
        char temp;
        inFS >> temp;
        return -1;
    }
    return 0;
}

#endif