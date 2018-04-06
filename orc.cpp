#include "orc.hpp"

Orc::Orc(std::string newName, int newHealth) : Enemy(newName, newHealth){
    Greataxe = new MeleeWeapon("Greataxe", "Melee", 10);
}

void Orc::attack(CombatUnit * target){
    int damage = -((Weapon*) Greataxe)->getDamage();
    target->modifyHealth(damage, target);
}