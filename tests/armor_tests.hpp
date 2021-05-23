#ifndef ARMOR_TESTS_HPP__
#define ARMOR_TESTS_HPP__

#include "gtest/gtest.h"
#include "../header/armor.hpp"
#include "../header/character.hpp"

TEST(ArmorTests, ArmorUseDefault) {
    Entity* character = new Character();
    baseItem* armor = new Armor();
    armor->use(character);
    EXPECT_EQ(character->getDefense(), 0);
}

TEST(ArmorTests, ArmorUseCustom) {
    Entity* character = new Character();
    baseItem* armor = new Armor("Skullflame Shield", "Armor", 48);
    armor->use(character);
    EXPECT_EQ(character->getDefense(), 48);
}

#endif