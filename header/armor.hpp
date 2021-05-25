#ifndef ARMORS_HPP
#define ARMORS_HPP

#include "baseItem.hpp"

class Armor : public baseItem {
    protected:
        int defense = 0;
    public:
        ~Armor() = default;
        Armor() : baseItem("", "Armor"), defense(0) {}
        Armor(string name, string type, int defense) 
            : baseItem(name, type), defense(defense) {}

        virtual void use(Entity* hero) {
            hero->setDefense(defense);
            hero->setCurrentArmor(this);
        }
        
        virtual void display() {
            cout << type << ": " << name << ", " << defense << " DEF" << endl;
        }
};

#endif