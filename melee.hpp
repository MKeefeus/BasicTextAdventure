#ifndef MELEE_HPP
#define MELEE_HPP

#include "weapon.hpp"
class MeleeWeapon : public Weapon{
public:
    MeleeWeapon(std::string, std::string, int);
};

#endif
