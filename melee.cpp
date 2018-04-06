#include "melee.hpp"
MeleeWeapon::MeleeWeapon(std::string newName, std::string newType, int newDamage) : Weapon(newName, newType, newDamage) {
    damage = newDamage;
}
