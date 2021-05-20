#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "baseItem.hpp"
#include "entity.hpp"
#include <iostream>

class Character : public Entity
{
    private:
        baseItem* inventory = nullptr;   // Points to an Inventory object
        string type = "";

    public:
        ~Character() { delete inventory; }
        Character () : Entity("", 0, 0, 0), type(""), inventory(nullptr) {} 
        Character (string _name, string _type, int _health, int _attack, int _defense, baseItem* _inventory) 
            : Entity(_name, _health, _attack, _defense), type(_type), inventory(_inventory) {}

        virtual void display()
        {
            cout << name << " : " << type << ", " << health << " HP, " << attack << " ATT, " << defense << " DEF" << endl;
            cout << "----------------------------------------------------" << endl;
        }
        
        // Setters
        virtual void heal(int h) { health += abs(h); }
        virtual void setAttack(int a) { attack = abs(a); }
        virtual void setDefense(int d) { defense = abs(d); }

        // Getters
        virtual string getType() { return type; }
        virtual baseItem* getInventory() { return inventory; }
};

#endif // CHARACTER_HPP