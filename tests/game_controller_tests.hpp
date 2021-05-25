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

    // EXPECT_TRUE(buffer.str() == "Bob is a Rougemouse!\n");

    // std::cout.rdbuf(sbuf);
}

#endif // 