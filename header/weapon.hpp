#ifndef WEAPONS_HPP
#define WEAPONS_HPP

#include <iostream>
#include <string>

#include "baseItem.hpp"

class Weapon : public baseItem {
    protected:
        int attack;
    public:
        Weapon() : baseItem("", "Weapon"), attack(0) {}
        Weapon(string n, string t, int a) : baseItem(n, t), attack(a) {}

        virtual void use(Entity* hero) {
            hero->setAttack(attack);
            hero->setCurrentWeapon(this);
        }

        virtual void display() {
            cout << type << ": " << name << ", " << attack << " ATT" << endl;
        }
};

#endif