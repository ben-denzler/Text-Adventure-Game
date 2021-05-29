#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "character.hpp"
#include "enemy.hpp"
#include "armor.hpp"
#include "weapon.hpp"
#include "consumable.hpp"
#include "inventory.hpp"

class AbstractFactory {
    public:
        virtual Entity* createEnemy(int) = 0;
        virtual Entity* createCharacter(string, int) = 0;
};

class EntityFactory : public AbstractFactory {
    private:
        string arrName[9] = { "Bird", "Cat", "Dinosaur", "Vagrant Mouse", "Very Large Bee", "Slippery Snake", "Angry Snail", "Doggy Who Lick", "Gorgonzolla, The Cheese Round of Death" };
    public:
        virtual Entity* createEnemy(int level) {
            string name = arrName[rand() % 9];
            return new Enemy(name, level);
        }
        virtual Entity* createCharacter(string name, int type);
};

Entity* EntityFactory::createCharacter(string name, int type) {
    // Initialize inventories
    baseItem* CharacterInventory = new Inventory("Character");
    baseItem* Armor = new Inventory("Armor");
    baseItem* Weapon = new Inventory("Weapon");
    baseItem* Consumable = new Inventory("Consumable");
    CharacterInventory->addItem(Armor);
    CharacterInventory->addItem(Weapon);
    CharacterInventory->addItem(Consumable);
    
    // Roguemouse
    if (type == 1) 
    { 
        baseItem* weapon = new ::Weapon("Sharpened Spoon", "Weapon", 20);
        baseItem* armor = new ::Armor("Leather Elbowpads", "Armor", 5);
        baseItem* consumable = new ::Consumable("Magic Mushnoom", "Consumable", 10, 17);

        CharacterInventory->addItem(weapon);
        CharacterInventory->addItem(armor);
        CharacterInventory->addItem(consumable);

        Character* newCharacter = new Character(name, "Roguemouse", 100, 0, 0, CharacterInventory);
        weapon->use(newCharacter);
        armor->use(newCharacter);

        return newCharacter;
    }
    // Swordmouse
    else if (type == 2)
    {
        baseItem* weapon = new ::Weapon("Wooden Toothpick", "Weapon", 75);
        baseItem* armor = new ::Armor("Mini Green Tunic", "Armor", 10);
        baseItem* consumable = new ::Consumable("Glass of Milk", "Consumable", 10, 17);
        
        CharacterInventory->addItem(weapon);
        CharacterInventory->addItem(armor);
        CharacterInventory->addItem(consumable);
        
        Character* newCharacter = new Character(name, "Swordmouse", 50, 0, 0, CharacterInventory);
        weapon->use(newCharacter);
        armor->use(newCharacter);

        return newCharacter;
    }
    // Monkmouse
    else
    {
        baseItem* weapon = new ::Weapon("Words of Wisdom", "Weapon", 30);
        baseItem* armor = new ::Armor("Torn Robe", "Armor", 15);
        baseItem* consumable = new ::Consumable("Green Tea", "Consumable", 10, 17);

        CharacterInventory->addItem(weapon);
        CharacterInventory->addItem(armor);
        CharacterInventory->addItem(consumable);
        
        Character* newCharacter = new Character(name, "Monkmouse", 45, 0, 0, CharacterInventory);
        weapon->use(newCharacter);
        armor->use(newCharacter);

        return newCharacter;
    }
}

#endif