#ifndef __INVENTORY_TESTS_HPP__
#define __INVENTORY_TESTS_HPP__

#include "gtest/gtest.h"
#include <iostream>
#include "../mock/Character_Mock.hpp"
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
    baseItem* consumable1 = new Consumable("Ravenous Anima Cell", "Consumable", 56, 17); //Maybe I did or didn't
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

    cout << "Inventory displayed before adding item: " << endl;
    Inventory->display();
    cout << endl;

    cout << "Invetory displayed after adding item: " << endl;
    baseItem* consumable3 = new Consumable("Potion of Phantom Fire", "Consumable", 0, 1726);
    Inventory->addItem(consumable3);
    Inventory->display();

    EXPECT_TRUE(true);
}

TEST(INVENTORY_TESTS, RemoveItem) {
    baseItem* testInventory = initInventory();

    cout << "RemoveItem vector before removing:" << endl;
    testInventory->display();
    cout << endl;

    baseItem* weapon = new Weapon("Thunderfury", "Weapon", 103);
    testInventory->removeItem(weapon);

    cout << "RemoveItem vector after removing:" << endl;
    testInventory->display();
}

TEST(INVENTORY_TESTS, DisplayWeapon)
{ 
    baseItem* my_inventory = initInventory();
    baseItem* weapon1 = new Weapon("stabber thing", "Weapon", 2);
    baseItem* weapon2 = new Weapon("my thumb", "Weapon", 3000);
    baseItem* weapon3 = new Weapon("someone else's thumb", "Weapon", 3000);
    my_inventory->addItem(weapon1);
    my_inventory->addItem(weapon2);
    my_inventory->addItem(weapon3);

    my_inventory->display();
}

#endif