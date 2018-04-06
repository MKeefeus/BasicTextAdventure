#include "ranged.hpp"

RangedWeapon::RangedWeapon(std::string newName, std::string newType, int newRange, int newDamage) : Weapon(newName, newType, newDamage){
	damage = newDamage;
	range = newRange;
}

int RangedWeapon::getRange() {
	return range;
}