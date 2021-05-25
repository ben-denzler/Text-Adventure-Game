#ifndef GAME_CONTROLLER_TEST_HPP
#define GAME_CONTROLLER_TEST_HPP

#include "gtest/gtest.h"
#include "../header/game_controller.hpp"

TEST(Game_Controller, createCharacter)
{
    // stringstream buffer;
    // streambuf *sbuf = cout.rdbuf();
    // cout.rdbuf(buffer.rdbuf());

    GameController* gameController = new GameController();
    gameController->createCharacter();

    EXPECT_TRUE(buffer.str() == "Please type the name of your character. Press Enter to continue.
bob

Choose the corresponding number of your class.n\1) Rougemouse - a fast mouse who specializes in small weaponary.\n2) Swordmouse - a gallant mouse who specializes in sword combat.\n3) Monkmouse - a wise mouse who specializes in using words and staffs.\n1\n\nSharpened Spoon is now added to your inventory!\nLeather Elbowpads is now added to your inventory!\nMagic Mushnoom is now added to your inventory!\n\nbob is a Roguemouse!\n");

    // std::cout.rdbuf(sbuf);
}

#endif // 