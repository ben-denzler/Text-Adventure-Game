#ifndef BASEITEM_HPP
#define BASEITEM_HPP

#include <string>
using namespace std;

class baseItem {
    protected:
        string name = "";
        string type = "";
    public:
        virtual void use() = 0;
        virtual string getName() { return name; }
        virtual string getType() { return type; }
        virtual string display() = 0;
}

#endif