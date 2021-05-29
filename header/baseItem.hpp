#ifndef BASEITEM_HPP
#define BASEITEM_HPP

#include "entity.hpp"
#include <string>

class baseItem {
    protected:
        string name = "";
        string type = "";
    public:
        virtual ~baseItem() {}
        baseItem(string n, string t) : name(n), type(t) {}
        virtual void display() = 0;
        virtual void use(Entity*) {}
        string getName() { return name; }
        string getType() { return type; }

        // For subclasses
        virtual void addToInventory(baseItem*){}
        virtual void addItem(baseItem*) {}
        virtual void removeItem(baseItem*) {}
        virtual int getSize() {}
        virtual baseItem* find(string itemName) { 
            if (itemName == this->getName()) { return this; }
            return nullptr;
        }
};

//

#endif
