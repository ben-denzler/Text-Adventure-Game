#ifndef ENTITY_MOCK_HPP
#define ENTITY_MOCK_HPP

#include <string>

class Entity_Mock {
    protected:
        std::string name = "Blob - the strongest blob alive!!";
        int health = 10;
        int attack = 0;
        int defense = 0;
    public:
        virtual void display() = 0;
        virtual void setAttack(int) {}
        virtual void setDefense(int) {}
        virtual void heal(int) {}
        void takeDamage(int damage);
        bool isDead() { return (health <= 0); }
        int getAttack() { return attack; }
        int getDefense() { return defense; }
};

#endif