#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "entity.hpp"
#include <cstdlib>
#include <iostream>

class Enemy: public Entity
{
    private:
        int level = 1;
    
    public:
        ~Enemy() = default;
        Enemy(string _name, int _level) : Entity(_name, 1, 1, 1), level(_level) { randomStats(); }

        void randomStats()
        {
            health = rand() % ((10 * level) + 1) + (5 * level);       // if level = 1, health is between 5 and 15
            attack = rand() % ((10 * level) + 1) + (5 * level);       
            defense = rand() % ((10 * level) + 1) + (5 * level);
        }

        virtual void display()
        {
            cout << name << " (LV " << level << ") : " << health << " HP, " << attack << " ATT, " << defense << " DEF" << endl;
        }
};

#endif // ENEMY_H