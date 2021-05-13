#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "baseItem.hpp"
#include <vector>
#include <iostream>

class Inventory : public baseItem {
    private:
        vector<baseItem*> inventory;
    public:
        ~Inventory();
        Inventory() : baseItem("", "Inventory"), inventory({}) {}
        Inventory(string n, string t) : baseItem(n, "Inventory") {}
        virtual void display();
        void addItem(baseItem*);
        void addInventory(baseItem* item) {
            inventory.push_back(item);
        }
        void removeItem(baseItem*);
};

Inventory::~Inventory() {
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory.at(i)->getType() == "Inventory") {
            for (int j = 0; j < inventory.size(); j++) {
                delete inventory.at(i).at(j);
            }
        }
        delete inventory.at(i);
    }
}

void Inventory::display() {
    for (unsigned int i = 0; i < inventory.size(); i++) {
        inventory.at(i)->display();
    }
}

void Inventory::addItem(baseItem* item)
{
    // If item is an inventory
    if (item->getType() == "Inventory") {
        this->inventory.push_back(item);
        return;
    }
    
    // If item is an inventory item
    /*Loop through inventory vector*/
    for(unsigned int i = 0; i < this->inventory.size(); i++)
    {
        if(this->inventory.at(i)->getName().find(item->getType()) != std::string::npos)
            {
                this->inventory.at(i)->addInventory(item);
                return;
            }
        }
    }
}


void Inventory::removeItem(baseItem* itemToRemove) {
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        // If inventory has sub-inventories, call recursively
        if (inventory.at(i)->getType() == "Inventory") {
            inventory.at(i)->removeItem(itemToRemove);
        }
        else {
            // Don't let player delete all items
            if (inventory.size() == 1) {
                cout << "It's a bad idea to delete all your items!" << endl;
                break;
            }
            // If item found, delete and erase from vector
            else if (inventory.at(i) == itemToRemove) {
                cout << inventory.at(i)->getName() << " has been deleted!" << endl;
                delete inventory.at(i);
                inventory.erase(inventory.begin() + i);
                break;
            }
        }
    }
}

#endif