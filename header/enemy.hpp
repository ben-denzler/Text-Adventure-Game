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
        Enemy(string _name) : Entity(_name, 1, 1, 1) { randomStats(); }

        void randomStats()
        {
            level = rand() % 5 + 1; // 1 - 5
            health = rand() % ((10 * level) + 1) + (5 * level);       // if level = 1, health is between 5 and 15
            attack = rand() % ((10 * level) + 1) + (5 * level);
            defense = rand() % ((10 * level) + 1) + (5 * level);
        }

        virtual void display()
        {
            cout << name << " (LVL " << level << ") : "  << ", " << health << "HP ," << attack << "ATT, " << defense << "DEF" << endl;
        }
};

#endif // ENEMY_H