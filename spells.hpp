#ifndef SPELLS_HPP
#define SPELLS_HPP

#include <iostream>

class Spell{
public:
    Spell(std::string, std::string, int, int);
    int getDamage();
    int getRange();
    std::string getName();
    std::string getType();
private:
    int range;
    int damage;
    std::string name;
    std::string type;
};

#endif
