#ifndef COMPOSITE_ARMORS_HPP
#define COMPOSITE_ARMORS_HPP

#include "baseItem.hpp"

class Armor : public baseItem {
    protected:
        int defense = 0;
    public:
        ~Armor() = default;
        Armor() : baseItem("", "Armor"), defense(0) {}
        Armor(string name, string type, int defense) 
            : baseItem(name, type), defense(defense) {}

        virtual void use(Character* hero) {
            hero->setDefense(defense);
        }

        virtual void display() {
            cout << type << ": " << name << ", " << defense << " DEF" << endl;
            // Armor: Cabalist's Hymnal, 207 DEF
        }
};

#endif