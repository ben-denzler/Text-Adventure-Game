#ifndef __WEAPON_TESTS_HPP__
#define __WEAPON_TESTS_HPP__

#include "gtest/gtest.h"
#include "../header/character.hpp"
#include "../header/weapon.hpp"

TEST(Weapon_tests, display)
{
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    baseItem* weapon = new Weapon("Good weapon", "wood", 2);
    weapon->display();

    EXPECT_TRUE(buffer.str() == "wood: Good weapon, 2 ATT\n");

    std::cout.rdbuf(sbuf);
}

TEST(Weapon_tests, UseWeapon)
{
    Entity* character = new Character();
    baseItem* weapon = new Weapon("Good weapon", "wood", 2);
    weapon->use(character);

    EXPECT_EQ(character->getAttack(), 2);
}

TEST(Weapon_tests, UseWeaponDefaultConstructor)
{
    Entity* character = new Character();
    baseItem* weapon = new Weapon();
    weapon->use(character);

    EXPECT_EQ(character->getAttack(), 0);
}

#endif