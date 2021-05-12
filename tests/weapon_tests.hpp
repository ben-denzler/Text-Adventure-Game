#ifndef __WEAPON_TESTS_HPP__
#define __WEAPON_TESTS_HPP__

#include "gtest/gtest.h"
#include "../mock/Entity_Mock.hpp"
#include "../mock/Character_Mock.hpp"
#include "../header/weapon.hpp"

TEST(Weapon_tests, UseWeapon)
{
    Entity_Mock* character = new Character_Mock();
    Weapon* weapon = new Weapon("Good weapon", "wood", 2);
    weapon->use(character);

    EXPECT_EQ(character->getAttack(), 2);
}

TEST(Weapon_tests, UseWeaponDefaultConstructor)
{
    Entity_Mock* character = new Character_Mock();
    Weapon* weapon = new Weapon();
    weapon->use(character);

    EXPECT_EQ(character->getAttack(), 0);
}

#endif