#ifndef __INVENTORY_TESTS_HPP__
#define __INVENTORY_TESTS_HPP__

#include "gtest/gtest.h"
#include <iostream>
#include <fstream>
#include "../header/inventory.hpp"
#include "../header/consumable.hpp"
#include "../header/armor.hpp"
#include "../header/weapon.hpp"

baseItem* initInventory() {
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

TEST(INVENTORY_TESTS, AddItem)
{ 
    baseItem* Inventory = initInventory();

    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());
    
    baseItem* consumable3 = new Consumable("Potion of Phantom Fire", "Consumable", 0, 1726);
    Inventory->addItem(consumable3);

    Inventory->display();

    EXPECT_TRUE(buffer.str() == "Potion of Phantom Fire is now added to your inventory!\nArmor: Weave of Warped Fates, 77 DEF\nArmor: Carved Ivory Keepsake, 38 DEF\nArmor: Titanic Ocular Gland, 77 DEF\nWeapon: Warglaive of Azzinoth, 289 ATT\nWeapon: Thunderfury, 103 ATT\nWeapon: Shadowmourne, 56 ATT\nConsumable: Ravenous Anima Cell, 17 HP, 56 DEF\nConsumable: Phial of Serenity, 90 HP, 5 DEF\nConsumable: Potion of Phantom Fire, 1726 HP, 0 DEF\nConsumable: Potion of Phantom Fire, 1726 HP, 0 DEF\n");

    // When done redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

TEST(INVENTORY_TESTS, AddToInventory)
{     
    baseItem* Pets = new Inventory("Pets");

    baseItem* Inventory = initInventory();
    Inventory->addToInventory(Pets);

    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    Inventory->display();

    EXPECT_TRUE(buffer.str() == "Armor: Weave of Warped Fates, 77 DEF\nArmor: Carved Ivory Keepsake, 38 DEF\nArmor: Titanic Ocular Gland, 77 DEF\nWeapon: Warglaive of Azzinoth, 289 ATT\nWeapon: Thunderfury, 103 ATT\nWeapon: Shadowmourne, 56 ATT\nConsumable: Ravenous Anima Cell, 17 HP, 56 DEF\nConsumable: Phial of Serenity, 90 HP, 5 DEF\nConsumable: Potion of Phantom Fire, 1726 HP, 0 DEF\n");

    // When done redirect cout to its old self
    std::cout.rdbuf(sbuf);

    //  Face: Smiley Face, 10000 ATT\n
}

TEST(INVENTORY_TESTS, RemoveItemTypical) {
    baseItem* testInventory = initInventory();

    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    baseItem* weapon = new Weapon("Thunderfury", "Weapon", 103);
    testInventory->removeItem(weapon);
    delete weapon;

    testInventory->display();

    EXPECT_TRUE(buffer.str() == "Thunderfury has been deleted!\nArmor: Weave of Warped Fates, 77 DEF\nArmor: Carved Ivory Keepsake, 38 DEF\nArmor: Titanic Ocular Gland, 77 DEF\nWeapon: Warglaive of Azzinoth, 289 ATT\nWeapon: Shadowmourne, 56 ATT\nConsumable: Ravenous Anima Cell, 17 HP, 56 DEF\nConsumable: Phial of Serenity, 90 HP, 5 DEF\nConsumable: Potion of Phantom Fire, 1726 HP, 0 DEF\n");

    // When done redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

TEST(INVENTORY_TESTS, RemoveAllItems) {
    baseItem* testInventory = initInventory();
    baseItem* weapon1 = new Weapon("Warglaive of Azzinoth", "Weapon", 289);
    baseItem* weapon2 = new Weapon("Thunderfury", "Weapon", 103);
    baseItem* weapon3 = new Weapon("Shadowmourne", "Weapon", 56);
    
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    testInventory->removeItem(weapon1);
    testInventory->removeItem(weapon2);
    testInventory->removeItem(weapon3);
    delete weapon1;
    delete weapon2;
    delete weapon3;

    EXPECT_TRUE(buffer.str() == "Warglaive of Azzinoth has been deleted!\nThunderfury has been deleted!\nIt's a bad idea to delete all your items!\n");

    // When done redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

TEST(INVENTORY_TESTS, RemoveNonexistentItem) {
    baseItem* testInventory = initInventory();
    baseItem* weapon = new Weapon("Gressil, Dawn of Ruin", "Weapon", 392);
    testInventory->removeItem(weapon);
    delete weapon;
    
    // Redirect cout to a buffer we can read for testing
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    testInventory->display();

    EXPECT_TRUE(buffer.str() == "Armor: Weave of Warped Fates, 77 DEF\nArmor: Carved Ivory Keepsake, 38 DEF\nArmor: Titanic Ocular Gland, 77 DEF\nWeapon: Warglaive of Azzinoth, 289 ATT\nWeapon: Thunderfury, 103 ATT\nWeapon: Shadowmourne, 56 ATT\nConsumable: Ravenous Anima Cell, 17 HP, 56 DEF\nConsumable: Phial of Serenity, 90 HP, 5 DEF\nConsumable: Potion of Phantom Fire, 1726 HP, 0 DEF\n");

    // When done, redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

TEST(INVENTORY_TESTS, RemoveAllConsumables_1) {
    baseItem* testInventory = initInventory();
    baseItem* consumable1 = new Consumable("Ravenous Anima Cell", "Consumable", 56, 17);
    baseItem* consumable2 =  new Consumable("Phial of Serenity", "Consumable", 5, 90);
    baseItem* consumable3 = new Consumable("Potion of Phantom Fire", "Consumable", 0, 1726);
    
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    testInventory->removeItem(consumable1);
    testInventory->removeItem(consumable2);
    testInventory->removeItem(consumable3);
    delete consumable1;
    delete consumable2;
    delete consumable3;

    EXPECT_TRUE(buffer.str() == "Ravenous Anima Cell has been deleted!\nPhial of Serenity has been deleted!\nPotion of Phantom Fire has been deleted!\n");

    // When done redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

TEST(INVENTORY_TESTS, RemoveAllConsumables_2) {
    baseItem* consumable1 = new Consumable("Ravenous Anima Cell", "Consumable", 56, 17);
    baseItem* consumable2 =  new Consumable("Phial of Serenity", "Consumable", 5, 90);
    baseItem* consumable3 = new Consumable("Potion of Phantom Fire", "Consumable", 0, 1726);
    baseItem* Consumable = new Inventory("Consumable");
    Consumable->addToInventory(consumable1);
    Consumable->addToInventory(consumable2);
    Consumable->addToInventory(consumable3);
    
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    Consumable->removeItem(consumable1);
    Consumable->removeItem(consumable2);
    Consumable->removeItem(consumable3);

    EXPECT_EQ(Consumable->getSize(), 0);

    // When done redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

TEST(INVENTORY_TESTS, DisplayWeapon)
{ 
    baseItem* my_inventory = initInventory();
    baseItem* weapon1 = new Weapon("stabber thing", "Weapon", 2);
    baseItem* weapon2 = new Weapon("my thumb", "Weapon", 3000);
    baseItem* weapon3 = new Weapon("someone else's thumb", "Weapon", 3000);

    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    my_inventory->addItem(weapon1);
    my_inventory->addItem(weapon2);
    my_inventory->addItem(weapon3);

    // Use cout as usual
    my_inventory->display();

    EXPECT_TRUE(buffer.str() == "stabber thing is now added to your inventory!\nmy thumb is now added to your inventory!\nsomeone else's thumb is now added to your inventory!\nArmor: Weave of Warped Fates, 77 DEF\nArmor: Carved Ivory Keepsake, 38 DEF\nArmor: Titanic Ocular Gland, 77 DEF\nWeapon: Warglaive of Azzinoth, 289 ATT\nWeapon: Thunderfury, 103 ATT\nWeapon: Shadowmourne, 56 ATT\nWeapon: stabber thing, 2 ATT\nWeapon: my thumb, 3000 ATT\nWeapon: someone else's thumb, 3000 ATT\nConsumable: Ravenous Anima Cell, 17 HP, 56 DEF\nConsumable: Phial of Serenity, 90 HP, 5 DEF\nConsumable: Potion of Phantom Fire, 1726 HP, 0 DEF\n");

    // When done redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

#endif