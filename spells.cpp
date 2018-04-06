#include "spells.hpp"

Spell::Spell(std::string newName, std::string newType, int newRange, int newDamage) {
    name = newName;
    type = newType;
    range = newRange;
    damage = newDamage;
}

int Spell::getDamage() {
    return damage;
}

int Spell::getRange() {
    return range;
}

std::string Spell::getName() {
    return name;
}

std::string Spell::getType() {
    return type;
}