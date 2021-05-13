#ifndef BASEITEM_HPP
#define BASEITEM_HPP

#include <string>
#include "../mocks/Entity_Mock.hpp"
#include "../mocks/Character_Mock.hpp"
using namespace std;

class baseItem {
    protected:
        string name = "";
        string type = "";
    public:
        baseItem(string n, string t) : name(n), type(t) {}
        virtual void use(Entity_Mock*) = 0;
        virtual void display() = 0;
        string getName() { return name; }
        string getType() { return type; }
};

#endif
