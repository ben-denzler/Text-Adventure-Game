#ifndef __INVENTORY_TESTS_HPP__
#define __INVENTORY_TESTS_HPP__

#include "gtest/gtest.h"
#include <iostream>
#include "../mock/Character_Mock.hpp"
#include "../header/inventory.hpp"
#include "../header/consumable.hpp"
#include "../header/armor.hpp"
#include "../header/weapon.hpp"

TEST(INVENTORY_TESTS, AddItems)
{ 
    baseItem* Obj = new consumable("apple", "consumable", 0, 10);

    EXPECT_TRUE();
   
}

#endif
