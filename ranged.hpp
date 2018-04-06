#ifndef RANGED_HPP
#define RANGED_HPP

#include "weapon.hpp"

class RangedWeapon : public Weapon{

public: 
	RangedWeapon(std::string,std::string, int, int);
    int getRange();
private:
	int range;
};

#endif