#ifndef __CONSUMABLE_TESTS_HPP__
#define __CONSUMABLE_TESTS_HPP__

#include "gtest/gtest.h"
#include <iostream>
#include "../mock/Character_Mock.hpp"
#include "../header/consumable.hpp"

/* Default constructor */

/*paramaterized constructor*/

/*use function*/
TEST(CONSUMABLE_TESTS, USE_FUNCTION)
{
    Character_Mock* character = new Character_Mock();
    baseItem* Obj = new Consumable("apple", "consumable", 0, 10);

    Obj->use(character);

    EXPECT_TRUE(20 == character->getHealth());
    EXPECT_TRUE(0 == character->getDefense());
   
}

/* display function */
TEST(CONSUMABLE_TESTS, DISPLAY_FUNCTION)
{
    baseItem* Obj = new Consumable("apple", "consumable", 0, 10);

    Obj->display();

   EXPECT_TRUE(true == true);
   
}

/*get name function */
TEST(CONSUMABLE_TESTS, GET_NAME_FUNCTION)
{ 
    baseItem* Obj = new Consumable("apple", "consumable", 0, 10);

    EXPECT_TRUE("apple" == Obj->getName());
   
}

#endif
