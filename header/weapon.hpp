#ifndef WEAPONS_HPP
#define WEAPONS_HPP

#include <string>
using namespace std;

class Weapon : public baseItem {
    protected:
        string name;
        string type;
        int attack;
    public:
        Weapon() : attack(0) { baseItem("", "Weapon"); }
        Weapon(string n, string t, int a) : attack(a) { baseItem(n, t); }

        virtual void use(Entity* hero) {
            hero.setAttack(attack);
        }

        virtual void display() {
            cout << type << ": " << name << ", " << attack << "ATT" << endl;
        }
}

#endif