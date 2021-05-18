#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
using namespace std;

class Entity
{
    protected:
      string name = "" ;
      int health = 0;
      int attack = 0;
      int defense = 0;

    public:
        virtual void display() = 0;
        void takeDamage(int damage) { health -= damage; }
        bool isDead() { return (health <= 0); }
        int getAttack() { return attack; }
        int getDefense() { return defense; }
};


#endif // ENTITY_HPP