#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
using namespace std;

class baseItem;

class Entity
{
    protected:
      string name = "" ;
      int health = 0;
      int attack = 0;
      int defense = 0;

    public:
        virtual ~Entity() {}
        Entity(string _name, int _health, int _attack, int _defense) 
            : name(_name), health(_health), attack(_attack), defense(_defense) {}

        virtual void display() = 0;
        void takeDamage(int damage) { if (damage > 0) health -= damage; }
        bool isDead() { return (health <= 0); }

        // Setters
        virtual void heal(int h) {}
        virtual void setAttack(int a) {}
        virtual void setDefense(int d) {}
        virtual void setCurrentArmor(baseItem* a) {}
        virtual void setCurrentWeapon(baseItem* w) {}

        // Getters
        int getAttack() { return attack; }
        int getDefense() { return defense; }
        int getHealth() { return health; }
        string getName() { return name; }
        virtual string getType() {}
        virtual baseItem* getInventory() { /*THROW EXCEPTIONS (if this is not a character)*/ }
        virtual baseItem* getCurrentArmor() {}
        virtual baseItem* getCurrentWeapon() {}
};

#endif // ENTITY_HPP