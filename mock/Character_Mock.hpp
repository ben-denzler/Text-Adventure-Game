#ifndef CHARACTER_MOCK_HPP
#define CHARACTER_MOCK_HPP

#include "Entity_Mock.hpp"

class Character_Mock: public Entity_Mock {
    private:
        string type = "Character";
        //vector<baseItem*> inventory;
    public:
        virtual void display() { cout << "Character display!" << endl; }
        void heal(int h) { health += h; }
        void setAttack(int a) { attack = a; }
        void setDefense(int d) { defense = d; }
        //void addItem() { inventory.addItem(); }
};

#endif