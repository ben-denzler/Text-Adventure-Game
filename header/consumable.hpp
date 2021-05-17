#ifndef CONSUMABLE_HPP
#define CONSUMABLE_HPP
#include "baseItem.hpp"
#include "../mock/Character_Mock.hpp"
#include <iostream>


class Consumable : public baseItem
{
    private:
        int defense = 0;
        int health =  0;

    public:
        Consumable(): baseItem(" ", "Consumable"), defense(0), health(0) {}
        
        Consumable(string _name, string _type, int _defense, int _health)
            : baseItem(_name, _type), defense(_defense), health(_health) {}

        virtual void use(Entity_Mock* e)
        {
            e->heal(health);
            e->setDefense(e->getDefense() + defense);
        }

        virtual void display()
        {
            /*consumable: apple, 10HP, 0 DEF */

            /* used for testing: std::cerr << type << ": " << name << ", " << health << " HP" << ", " << defense << " DEF"<< endl ; */
            cout  << type << ": " << name << ", " << health << " HP" << ", " << defense << " DEF"<< endl;
        }

        string getName()
        {
            return name;
        }

        /* used for testing ONLY */
        string getData()
        {
            string data = name + " " + type + " " +  to_string(defense) + " " + to_string(health);
            return data;
        }
        
};


#endif
