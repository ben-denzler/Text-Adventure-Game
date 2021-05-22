#ifndef WEAPONS_HPP
#define WEAPONS_HPP

#include <iostream>
#include <string>

#include "baseItem.hpp"
#include "../mock/Entity_Mock.hpp"
#include "../mock/Character_Mock.hpp"

class Weapon : public baseItem {
    protected:
        int attack;
    public:
        Weapon() : baseItem("", "Weapon"), attack(0) {}
        Weapon(string n, string t, int a) : baseItem(n, t), attack(a) {}

        virtual void use(Entity_Mock* hero) {
            hero->setAttack(attack);
        }

        virtual void display() {
            cout << type << ": " << name << ", " << attack << " ATT" << endl;
        }
};

#endif