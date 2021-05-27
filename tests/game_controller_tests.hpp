#ifndef GAME_CONTROLLER_TEST_HPP
#define GAME_CONTROLLER_TEST_HPP

#include "gtest/gtest.h"
#include "../header/game_controller.hpp"

TEST(Game_Controller, createCharacter)
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

    EXPECT_TRUE(buffer.str() == "Please type the name of your character. Press Enter to continue.\n\nChoose the corresponding number of your class.\n1) Rougemouse - a fast mouse who specializes in small weaponary.\n2) Swordmouse - a gallant mouse who specializes in sword combat.\n3) Monkmouse - a wise mouse who specializes in using words and staffs.\n\nSharpened Spoon is now added to your inventory!\nLeather Elbowpads is now added to your inventory!\nMagic Mushnoom is now added to your inventory!\n\nbob is a Roguemouse!\n");

    std::cout.rdbuf(sbuf);
}

TEST(Game_Controller, createCharacter_MultiNumInput)
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

    EXPECT_TRUE(buffer.str() == "Please type the name of your character. Press Enter to continue.\n\nChoose the corresponding number of your class.\n1) Rougemouse - a fast mouse who specializes in small weaponary.\n2) Swordmouse - a gallant mouse who specializes in sword combat.\n3) Monkmouse - a wise mouse who specializes in using words and staffs.\n\nWords of Wisdom is now added to your inventory!\nTorn Robe is now added to your inventory!\nGreen Tea is now added to your inventory!\n\nbob is a Monkmouse!\nPlease type the name of your character. Press Enter to continue.\n\nChoose the corresponding number of your class.\n1) Rougemouse - a fast mouse who specializes in small weaponary.\n2) Swordmouse - a gallant mouse who specializes in sword combat.\n3) Monkmouse - a wise mouse who specializes in using words and staffs.\n\nWooden Toothpick is now added to your inventory!\nMini Green Tunic is now added to your inventory!\nGlass of Milk is now added to your inventory!\n\ndory is a Swordmouse!\n");

    std::cout.rdbuf(sbuf);
}

#endif // 