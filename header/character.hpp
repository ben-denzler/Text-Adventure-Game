#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "baseItem.hpp"
#include <iostream>

class Character : public Entity
{
    private:
        baseItem* inventory = nullptr;   // Points to an Inventory object
        baseItem* currArmor = nullptr;
        baseItem* currWeapon = nullptr;
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
        virtual void setCurrentArmor(baseItem* a) { currArmor = a; }
        virtual void setCurrentWeapon(baseItem* w) { currWeapon = w; }

        // Getters
        virtual string getType() { return type; }
        baseItem* getInventory() { return inventory; }
        virtual baseItem* getCurrentArmor() { return currArmor; }
        virtual baseItem* getCurrentWeapon() { return currWeapon; }
};
    
#endif // CHARACTER_HPP