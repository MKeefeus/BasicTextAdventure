#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "item.hpp"

class Weapon : public Item{
public:
    Weapon();
    Weapon(std::string, std::string, int);
    int getDamage();

protected:
    int damage;
};
#endif
