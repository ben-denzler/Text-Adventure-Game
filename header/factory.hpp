#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "character.hpp"
#include "enemy.hpp"
#include "baseItem.hpp"
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
        string arrName[3] = {"Bird", "Cat", "Dinosaur"};
        enum classNames { Roguemouse, Swordsmouse, Monkmouse };
    public:
        virtual Entity* createEnemy(int level) {
            string name = arrName[rand() % 3];
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
    if (type == 1) { 
        CharacterInventory->addItem(new ::Weapon("Sharpened Spoon", "Weapon", 20));
        CharacterInventory->addItem(new ::Armor("Leather Elbowpads", "Armor", 20));
        CharacterInventory->addItem(new ::Consumable("Magic Mushnoom", "Consumable", 10, 17));
        return new Character(name, "Roguemouse", 100, 20, 5, CharacterInventory);
    }
    // Swordsmouse
    else if (type == 2)
    {
        CharacterInventory->addItem(new ::Weapon("Wooden Toothpick", "Weapon", 20));
        CharacterInventory->addItem(new ::Armor("Mini Green Tunic", "Armor", 20));
        CharacterInventory->addItem(new ::Consumable("Glass of Milk", "Consumable", 10, 17));
        return new Character(name, "Swordmouse", 50, 75, 10, CharacterInventory);
    }
    // Monkmouse
    else
    {
        CharacterInventory->addItem(new ::Weapon("Words of Wisdom", "Weapon", 20));
        CharacterInventory->addItem(new ::Armor("Torn Robe", "Armor", 20));
        CharacterInventory->addItem(new ::Consumable("Green Tea", "Consumable", 10, 17));
        return new Character(name, "Monkmouse", 45, 30, 15, CharacterInventory);
    }
}

#endif