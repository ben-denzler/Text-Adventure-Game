#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "baseItem.hpp"
#include "entity.hpp"
#include <iostream>

class Character : public Entity
{
    private:
        baseItem* inventory;   // Points to an Inventory object
        string type = "";

    public:
        Character (string _name, string _type, int _health, int _attack, int _defense, baseItem* _inventory) 
            : Entity(_name, _health, _attack, _defense), type(_type), inventory(_inventory) {}

        virtual void display()
        {
            cout << name << " : " << type << ", ", << health << "HP ," << attack << "ATT, " << defense << "DEF" << endl;
            cout << "------------------------------------------------------------------------------" << endl;
        }
        
        void heal(int h) { health += h; }
        void setAttack(int a) { attack = a; }
        void setDefense(int d) { defense = d; }
        baseItem* getInventory() { return inventory; }
};

#endif // CHARACTER_HPP