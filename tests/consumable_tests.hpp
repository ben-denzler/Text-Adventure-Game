#ifndef CONSUMABLE_TESTS_HPP
#define CONSUMABLE_TESTS_HPP

#include "gtest/gtest.h"
#include <iostream>
#include "../header/character.hpp"
#include "../header/consumable.hpp"

/* Default constructor */

/*paramaterized constructor*/

/*use function*/
TEST(CONSUMABLE_TESTS, USE_FUNCTION)
{
    Entity* character = new Character();
    baseItem* Obj = new Consumable("apple", "consumable", 0, 10);

    Obj->use(character);

    EXPECT_TRUE(10 == character->getHealth());
    EXPECT_TRUE(0 == character->getDefense());
   
}

/* display function */
TEST(CONSUMABLE_TESTS, DISPLAY_FUNCTION)
{
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    baseItem* Obj = new Consumable("apple", "consumable", 0, 10);

    Obj->display();
   
   EXPECT_TRUE(buffer.str() == "consumable: apple, 10 HP, 0 DEF\n");

    std::cout.rdbuf(sbuf);
}

/*get name function */
TEST(CONSUMABLE_TESTS, GET_NAME_FUNCTION)
{ 
    baseItem* Obj = new Consumable("apple", "consumable", 0, 10);

    EXPECT_TRUE("apple" == Obj->getName());
   
}

#endif
