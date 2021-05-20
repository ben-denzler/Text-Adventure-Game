#ifndef __CHARACTER_TESTS_HPP__
#define __CHARACTER_TESTS_HPP__

#include "gtest/gtest.h"
#include "../header/character.hpp"
#include "../header/inventory.hpp"
#include "../header/consumable.hpp"
#include "../header/armor.hpp"
#include "../header/weapon.hpp"

baseItem* initInventory2() {
    // Armors
    baseItem* armor1 = new Armor("Weave of Warped Fates", "Armor", 77);
    baseItem* armor2 = new Armor("Carved Ivory Keepsake", "Armor", 38);
    baseItem* armor3 = new Armor("Titanic Ocular Gland", "Armor", 77);

    // Weapons
    baseItem* weapon1 = new Weapon("Warglaive of Azzinoth", "Weapon", 289);
    baseItem* weapon2 = new Weapon("Thunderfury", "Weapon", 103);
    baseItem* weapon3 = new Weapon("Shadowmourne", "Weapon", 56);

    // Consumables
    baseItem* consumable1 = new Consumable("Ravenous Anima Cell", "Consumable", 56, 17);
    baseItem* consumable2 =  new Consumable("Phial of Serenity", "Consumable", 5, 90);
    baseItem* consumable3 = new Consumable("Potion of Phantom Fire", "Consumable", 0, 1726);
    
    // Inventories
    baseItem* CharacterInventory = new Inventory("Character");
    baseItem* Armor = new Inventory("Armor");
    baseItem* Weapon = new Inventory("Weapon");
    baseItem* Consumable = new Inventory("Consumable");

    // Add Armors to Armor inventory
    Armor->addToInventory(armor1);
    Armor->addToInventory(armor2);
    Armor->addToInventory(armor3);
    
    // Add Weapons to Weapon inventory
    Weapon->addToInventory(weapon1);
    Weapon->addToInventory(weapon2);
    Weapon->addToInventory(weapon3);

    // Add Consumables to Consumable inventory
    Consumable->addToInventory(consumable1);
    Consumable->addToInventory(consumable2);
    Consumable->addToInventory(consumable3);
    
    // Add all inventories to main inventory
    CharacterInventory->addToInventory(Armor);
    CharacterInventory->addToInventory(Weapon);
    CharacterInventory->addToInventory(Consumable);

    return CharacterInventory;
}

TEST(CharacterTests, CharacterCreation) {
    baseItem* my_inventory = initInventory2();
    Entity* character = new Character("Bob The Builder", "Builder", 100, 3, 40, my_inventory);
    
    EXPECT_TRUE(character->getName() == "Bob The Builder");
    EXPECT_TRUE(character->getType() == "Builder");
    EXPECT_TRUE(character->getHealth() == 100);
    EXPECT_TRUE(character->getAttack() == 3);
    EXPECT_TRUE(character->getDefense() == 40);
    EXPECT_TRUE(character->getInventory() == my_inventory);
}

TEST(CharacterTests, CharacterCreationDefault) {
    baseItem* my_inventory = initInventory2();
    Entity* character = new Character();
    
    EXPECT_TRUE(character->getName() == "");
    EXPECT_TRUE(character->getType() == "");
    EXPECT_TRUE(character->getHealth() == 0);
    EXPECT_TRUE(character->getAttack() == 0);
    EXPECT_TRUE(character->getDefense() == 0);
    EXPECT_TRUE(character->getInventory() == nullptr);
}

TEST(CharacterTests, CharacterDisplay) {
    baseItem* my_inventory = initInventory2();
    Entity* character = new Character("Bob The Builder", "Builder", 100, 3, 40, my_inventory);

    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    character->display();
    
    EXPECT_TRUE(buffer.str() == "Bob The Builder : Builder, 100 HP, 3 ATT, 40 DEF\n----------------------------------------------------\n");

    std::cout.rdbuf(sbuf);
}

TEST(CharacterTests, DefaultCharacterHeal) {
    baseItem* my_inventory = initInventory2();
    Entity* character = new Character();

    character->heal(20);
    EXPECT_TRUE(character->getHealth() == 20);
    character->heal(20);
    EXPECT_TRUE(character->getHealth() == 40);
    character->heal(-2);
    EXPECT_TRUE(character->getHealth() == 42);
    character->heal(0);
    EXPECT_TRUE(character->getHealth() == 42);
}

TEST(CharacterTests, CharacterHeal) {
    baseItem* my_inventory = initInventory2();
    Entity* character = new Character("Bob The Builder", "Builder", 100, 3, 40, my_inventory);

    character->heal(20);
    EXPECT_TRUE(character->getHealth() == 120);
    character->heal(20);
    EXPECT_TRUE(character->getHealth() == 140);
    character->heal(-2);
    EXPECT_TRUE(character->getHealth() == 142);
    character->heal(0);
    EXPECT_TRUE(character->getHealth() == 142);
}

TEST(CharacterTests, CharacterSetAttack) {
    
    Entity* character = new Character();
    
    character->setAttack(10);
    EXPECT_TRUE(character->getAttack() ==  10);
    character->setAttack(1);
    EXPECT_TRUE(character->getAttack() ==  1);
}

TEST(CharacterTests, CharacterSetDefense) {

    Entity* character = new Character();
    
    character->setDefense(100);
    EXPECT_TRUE(character->getDefense() ==  100);
    character->setDefense(50);
    EXPECT_TRUE(character->getDefense() ==  50);
}

TEST(CharacterTests, CharacterTakeDamage)
{
    baseItem* my_inventory = initInventory2();
    Entity* character = new Character("Boots", "Stinky Footwear", 15, 3, 40, my_inventory);
    character->takeDamage(15);

    EXPECT_TRUE(character->getHealth() == 0);
}

TEST(CharacterTests, CharacterIsDead) {
    baseItem* my_inventory = initInventory2();
    Entity* character = new Character("Boots", "Abominable Henchman of Dora", 15, 3, 40, my_inventory);

    EXPECT_FALSE(character->isDead());
    character->takeDamage(15);
    EXPECT_TRUE(character->isDead());
}

#endif