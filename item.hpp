#ifndef ITEM_HPP
#define ITEM_HPP
#include <vector>
#include <iostream>
#include <string>

class Item{
public:
    Item();
    Item(std::string, std::string); //(type)
    std::string getName();
    std::string getType();
protected:
    std::string name;
    std::string type;
};

#endif
