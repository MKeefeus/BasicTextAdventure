#include "weapon.hpp"

Weapon::Weapon() {

}

Weapon::Weapon(std::string newName, std::string newType, int newDamage) {
    name = newName;
    type = newType;
    damage = newDamage;
}

int Weapon::getDamage() {
    return damage;
}