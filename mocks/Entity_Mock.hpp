#ifndef ENTITY_MOCK_HPP
#define ENTITY_MOCK_HPP

#include <string>
using namespace std;

class Entity_Mock {
    protected:
        string name = "Blob - the strongest blob alive!!";
        int health = 10;
        int attack = 5000;
        int defense = 2;
    public:
        virtual void display() = 0;
        virtual void setAttack(int) {}
        void takeDamage(int damage);
        bool isDead() { return (health <= 0); }
        int getAttack() { return attack; }
        int getDefense() { return defense; }
};

#endif
