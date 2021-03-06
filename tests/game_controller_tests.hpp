#ifndef GAME_CONTROLLER_TEST_HPP
#define GAME_CONTROLLER_TEST_HPP

#include "gtest/gtest.h"
#include "../header/game_controller.hpp"

TEST(Game_Controller_Create, createCharacter)
{
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    ifstream inFS;

    inFS.open("test_files/Game_Controller_createCharacter.txt");
    if (!inFS.is_open()) {
        cout << "Sorry, bad file." << endl;
        exit(0);
    }

    GameController* gameController = new GameController();
    gameController->createCharacter(inFS);

    inFS.close();

    EXPECT_TRUE(buffer.str() == "Please type the name of your character. Press Enter to continue.\n\nChoose the corresponding number of your class.\n1) Rougemouse - a fast mouse who specializes in small weaponary.\n2) Swordmouse - a gallant mouse who specializes in sword combat.\n3) Monkmouse - a wise mouse who specializes in using words and staffs.\n\nSharpened Spoon is now added to your inventory!\nLeather Elbowpads is now added to your inventory!\nMagic Mushnoom is now added to your inventory!\n\nbob is a Roguemouse!\n\n");

    std::cout.rdbuf(sbuf);
}

TEST(Game_Controller_Create, createCharacter_MultiNumInput)
{
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    ifstream inFS;

    inFS.open("test_files/Game_Controller_createCharacter_MultiNumInput.txt");
    if (!inFS.is_open()) {
        cout << "Sorry, bad file." << endl;
        exit(0);
    }

    GameController* gameController = new GameController();
    gameController->createCharacter(inFS);
    gameController->createCharacter(inFS);

    inFS.close();

    EXPECT_TRUE(buffer.str() == "Please type the name of your character. Press Enter to continue.\n\nChoose the corresponding number of your class.\n1) Rougemouse - a fast mouse who specializes in small weaponary.\n2) Swordmouse - a gallant mouse who specializes in sword combat.\n3) Monkmouse - a wise mouse who specializes in using words and staffs.\n\nWords of Wisdom is now added to your inventory!\nTorn Robe is now added to your inventory!\nGreen Tea is now added to your inventory!\n\nbob is a Monkmouse!\n\nPlease type the name of your character. Press Enter to continue.\n\nChoose the corresponding number of your class.\n1) Rougemouse - a fast mouse who specializes in small weaponary.\n2) Swordmouse - a gallant mouse who specializes in sword combat.\n3) Monkmouse - a wise mouse who specializes in using words and staffs.\n\nWooden Toothpick is now added to your inventory!\nMini Green Tunic is now added to your inventory!\nGlass of Milk is now added to your inventory!\n\ndory is a Swordmouse!\n\n");

    std::cout.rdbuf(sbuf);
}

TEST(Game_Controller_Create, createEnemies)
{
    GameController* gameController = new GameController();
    gameController->createEnemies();

    // enemies: {lv 3, lv 2, lv 1}
    EXPECT_TRUE((gameController->getEnemy(2)->getHealth() >= 5) && (gameController->getEnemy(2)->getHealth() <= 15));
    EXPECT_TRUE((gameController->getEnemy(2)->getAttack() >= 5) && (gameController->getEnemy(2)->getAttack() <= 15));
    EXPECT_TRUE((gameController->getEnemy(2)->getDefense() >= 5) && (gameController->getEnemy(2)->getDefense() <= 15));

    EXPECT_TRUE((gameController->getEnemy(1)->getHealth() >= 10) && (gameController->getEnemy(1)->getHealth() <= 30));
    EXPECT_TRUE((gameController->getEnemy(1)->getAttack() >= 10) && (gameController->getEnemy(1)->getAttack() <= 30));
    EXPECT_TRUE((gameController->getEnemy(1)->getDefense() >= 10) && (gameController->getEnemy(1)->getHealth() <= 30));

    EXPECT_TRUE((gameController->getEnemy(0)->getHealth() >= 15) && (gameController->getEnemy(0)->getHealth() <= 45));
    EXPECT_TRUE((gameController->getEnemy(0)->getAttack() >= 15) && (gameController->getEnemy(0)->getAttack() <= 45));
    EXPECT_TRUE((gameController->getEnemy(0)->getDefense() >= 15) && (gameController->getEnemy(0)->getHealth() <= 45));
}

TEST(Game_Controller_Battle, displayBattleOptions)
{
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    ifstream inFS;

    inFS.open("test_files/Game_Controller_displayBattleOptions.txt");
    if (!inFS.is_open()) {
        cout << "Sorry, bad file." << endl;
        exit(0);
    }

    GameController* gameController = new GameController();
    int val1 = gameController->displayBattleOptions(inFS);
    int val2 = gameController->displayBattleOptions(inFS);

    inFS.close();

    EXPECT_EQ(val1, 1);
    EXPECT_EQ(val2, 4);

    std::cout.rdbuf(sbuf);
}

TEST(Game_Controller_Battle, BattleFunctionTestOption4Weapon)
{
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    ifstream inFS;

    inFS.open("test_files/Game_Controller_BattleFunctionTestOption4Weapon.txt");
    if (!inFS.is_open()) {
        cout << "Sorry, bad file." << endl;
        exit(0);
    }

    GameController* gameController = new GameController();
    gameController->createCharacter(inFS);

    // Original Weapon
    EXPECT_TRUE(gameController->getCurrCharacter()->getCurrentWeapon()->getName() == "Words of Wisdom");
    EXPECT_TRUE(gameController->getCurrCharacter()->getAttack() == 30);

    // Words of Wisdom (ATT == 30)
    gameController->evalBattleChoice(4, inFS);          // Use Weapon (Change stats)
    EXPECT_TRUE(gameController->getCurrCharacter()->getCurrentWeapon()->getName() == "Words of Wisdom");
    EXPECT_TRUE(gameController->getCurrCharacter()->getAttack() == 30);

    EXPECT_TRUE(buffer.str() == "Please type the name of your character. Press Enter to continue.\n\nChoose the corresponding number of your class.\n1) Rougemouse - a fast mouse who specializes in small weaponary.\n2) Swordmouse - a gallant mouse who specializes in sword combat.\n3) Monkmouse - a wise mouse who specializes in using words and staffs.\n\nWords of Wisdom is now added to your inventory!\nTorn Robe is now added to your inventory!\nGreen Tea is now added to your inventory!\n\nJohn is a Monkmouse!\n\n----------------------------------------------------\nINVENTORY: Armor, Weapons & Consumables\nArmor: Torn Robe, 15 DEF\nWeapon: Words of Wisdom, 30 ATT\nConsumable: Green Tea, 17 HP, 10 DEF\n----------------------------------------------------\nChoose your item by typing its name (Case Matters). Press Enter to continue.\n\nPlayer equips Words of Wisdom!\n\n");

    inFS.close();

    std::cout.rdbuf(sbuf);
}

TEST(Game_Controller_Battle, BattleFunctionTestOption4Armor)
{
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    ifstream inFS;

    inFS.open("test_files/Game_Controller_BattleFunctionTestOption4Armor.txt");
    if (!inFS.is_open()) {
        cout << "Sorry, bad file." << endl;
        exit(0);
    }

    GameController* gameController = new GameController();
    gameController->createCharacter(inFS);

    // Original Weapon
    EXPECT_TRUE(gameController->getCurrCharacter()->getCurrentArmor()->getName() == "Torn Robe");
    EXPECT_TRUE(gameController->getCurrCharacter()->getDefense() == 15);

    // Words of Wisdom (ATT == 30)
    gameController->evalBattleChoice(4, inFS);          // Use Armor (Change stats)
    EXPECT_TRUE(gameController->getCurrCharacter()->getCurrentArmor()->getName() == "Torn Robe");
    EXPECT_TRUE(gameController->getCurrCharacter()->getDefense() == 15);

    EXPECT_TRUE(buffer.str() == "Please type the name of your character. Press Enter to continue.\n\nChoose the corresponding number of your class.\n1) Rougemouse - a fast mouse who specializes in small weaponary.\n2) Swordmouse - a gallant mouse who specializes in sword combat.\n3) Monkmouse - a wise mouse who specializes in using words and staffs.\n\nWords of Wisdom is now added to your inventory!\nTorn Robe is now added to your inventory!\nGreen Tea is now added to your inventory!\n\nJohn is a Monkmouse!\n\n----------------------------------------------------\nINVENTORY: Armor, Weapons & Consumables\nArmor: Torn Robe, 15 DEF\nWeapon: Words of Wisdom, 30 ATT\nConsumable: Green Tea, 17 HP, 10 DEF\n----------------------------------------------------\nChoose your item by typing its name (Case Matters). Press Enter to continue.\n\nPlayer equips Torn Robe!\n\n");

    inFS.close();

    std::cout.rdbuf(sbuf);
}

TEST(Game_Controller_Battle, BattleFunctionTestOption4Consumable)
{
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    ifstream inFS;

    inFS.open("test_files/Game_Controller_BattleFunctionTestOption4Consumable.txt");
    if (!inFS.is_open()) {
        cout << "Sorry, bad file." << endl;
        exit(0);
    }

    GameController* gameController = new GameController();
    gameController->createCharacter(inFS);

    // Original Consumer
    baseItem* foundItem1 = gameController->getCurrCharacter()->getInventory()->find("Green Tea");
    EXPECT_TRUE(foundItem1 != nullptr);
    EXPECT_TRUE(gameController->getCurrCharacter()->getHealth() == 45);
    EXPECT_TRUE(gameController->getCurrCharacter()->getDefense() == 15);

    // Green Tea (10def, 17health)
    gameController->evalBattleChoice(4, inFS);          // Use Consumable (Change stats)
    baseItem* foundItem2 = gameController->getCurrCharacter()->getInventory()->find("Green Tea");
    EXPECT_TRUE(foundItem2 == nullptr);
    EXPECT_TRUE(gameController->getCurrCharacter()->getHealth() == 62);
    EXPECT_TRUE(gameController->getCurrCharacter()->getDefense() == 25);

    EXPECT_TRUE(buffer.str() == "Please type the name of your character. Press Enter to continue.\n\nChoose the corresponding number of your class.\n1) Rougemouse - a fast mouse who specializes in small weaponary.\n2) Swordmouse - a gallant mouse who specializes in sword combat.\n3) Monkmouse - a wise mouse who specializes in using words and staffs.\n\nWords of Wisdom is now added to your inventory!\nTorn Robe is now added to your inventory!\nGreen Tea is now added to your inventory!\n\nJohn is a Monkmouse!\n\n----------------------------------------------------\nINVENTORY: Armor, Weapons & Consumables\nArmor: Torn Robe, 15 DEF\nWeapon: Words of Wisdom, 30 ATT\nConsumable: Green Tea, 17 HP, 10 DEF\n----------------------------------------------------\nChoose your item by typing its name (Case Matters). Press Enter to continue.\n\nPlayer uses Green Tea!\nGreen Tea has been deleted!\n\n");

    inFS.close();

    std::cout.rdbuf(sbuf);
}

TEST(Game_Controller_Battle, BattleFunctionTestOption4ArmorInvalid)
{
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    ifstream inFS;

    inFS.open("test_files/Game_Controller_BattleFunctionTestOption4ArmorInvalid.txt");
    if (!inFS.is_open()) {
        cout << "Sorry, bad file." << endl;
        exit(0);
    }

    GameController* gameController = new GameController();
    gameController->createCharacter(inFS);

    // Original Weapon
    EXPECT_TRUE(gameController->getCurrCharacter()->getCurrentArmor()->getName() == "Torn Robe");
    EXPECT_TRUE(gameController->getCurrCharacter()->getDefense() == 15);

    // Words of Wisdom (ATT == 30)
    gameController->evalBattleChoice(4, inFS);          // Use Armor (Change stats)
    EXPECT_TRUE(gameController->getCurrCharacter()->getCurrentArmor()->getName() == "Torn Robe");
    EXPECT_TRUE(gameController->getCurrCharacter()->getDefense() == 15);

    EXPECT_TRUE(buffer.str() == "Please type the name of your character. Press Enter to continue.\n\nChoose the corresponding number of your class.\n1) Rougemouse - a fast mouse who specializes in small weaponary.\n2) Swordmouse - a gallant mouse who specializes in sword combat.\n3) Monkmouse - a wise mouse who specializes in using words and staffs.\n\nWords of Wisdom is now added to your inventory!\nTorn Robe is now added to your inventory!\nGreen Tea is now added to your inventory!\n\nJohn is a Monkmouse!\n\n----------------------------------------------------\nINVENTORY: Armor, Weapons & Consumables\nArmor: Torn Robe, 15 DEF\nWeapon: Words of Wisdom, 30 ATT\nConsumable: Green Tea, 17 HP, 10 DEF\n----------------------------------------------------\nChoose your item by typing its name (Case Matters). Press Enter to continue.\n\nERROR: ITEM NOT FOUND. Please type the item's name again.\n\nPlayer equips Torn Robe!\n\n");

    inFS.close();

    std::cout.rdbuf(sbuf);
}

TEST(Game_Controller_Narrative, getNarrative_Choice1) {

    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    ifstream script;

    script.open("test_files/test_script.txt");
    if (!script.is_open()) {
        cout << "Sorry, bad file." << endl;
        exit(0);
    }

    ifstream player_input;

    player_input.open("test_files/Game_Controller_getNarrative_1.txt");
    if (!player_input.is_open()) {
        cout << "Sorry, bad file." << endl;
        exit(0);
    }

    GameController* gameController = new GameController();
    gameController->createCharacter(player_input);

    std::cout.rdbuf(sbuf);

    stringstream buffer1;
    streambuf *sbuf1 = cout.rdbuf();
    cout.rdbuf(buffer1.rdbuf());

    int result;
    // Get Narrative (Dialogue 1)
    result = gameController->getNarrative(script, player_input);
    EXPECT_TRUE(result == 0);
    EXPECT_TRUE(buffer1.str() == "Dialogue 1\n");

    // // Get Narrative (Dialogue 2)
    result = gameController->getNarrative(script, player_input);
    EXPECT_TRUE(result == 0);
    EXPECT_TRUE(buffer1.str() == "Dialogue 1\nDialogue 2\n");

    // Get Narrative (CHOICE)
    // Get Narrative (This is a choice prompt)
    // Get Narrative (1) Choice #1)
    // Get Narrative (2) Choice #2)
    // Get Narrative (You died!)
    // Get Narrative (You lived!)
    result = gameController->getNarrative(script, player_input);
    EXPECT_TRUE(result == 0);
    EXPECT_TRUE(buffer1.str() == "Dialogue 1\nDialogue 2\nThis is a choice prompt\n\n1) Choice #1\n2) Choice #2\n\nMake a choice by typing 1 or 2...\n\nYou died!\n\n");

    // // Get Narrative (Dialogue 3)
    result = gameController->getNarrative(script, player_input);
    EXPECT_TRUE(result == 0);
    EXPECT_TRUE(buffer1.str() == "Dialogue 1\nDialogue 2\nThis is a choice prompt\n\n1) Choice #1\n2) Choice #2\n\nMake a choice by typing 1 or 2...\n\nYou died!\n\nDialogue 3\n");

    // // Get Narrative (END)
    result = gameController->getNarrative(script, player_input);
    EXPECT_TRUE(result == -1);
    EXPECT_TRUE(buffer1.str() == "Dialogue 1\nDialogue 2\nThis is a choice prompt\n\n1) Choice #1\n2) Choice #2\n\nMake a choice by typing 1 or 2...\n\nYou died!\n\nDialogue 3\nYou have finished the game! Congrats!\nPress ENTER key to exit.\n");

    script.close();
    player_input.close();

    std::cout.rdbuf(sbuf1);
}

TEST(Game_Controller_Battle, Battle1) 
{
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    ifstream inFS;

    inFS.open("test_files/Game_Controller_Battle1.txt");
    if (!inFS.is_open()) {
        cout << "Sorry, bad file." << endl;
        exit(0);
    }

    GameController* gameController = new GameController();
    gameController->createCharacter(inFS);
    gameController->createEnemies();

    // Enemy dies (ATTACK EVERY TIME)
    int result = gameController->battle(inFS);
    EXPECT_EQ(result, 0);

    // Character Dies (DEFEND EVERY TIME)
    result = gameController->battle(inFS);
    EXPECT_EQ(result, -1);

    inFS.close();

    std::cout.rdbuf(sbuf);
}

#endif