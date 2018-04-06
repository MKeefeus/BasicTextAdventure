#include "goblin.hpp"

Goblin::Goblin(std::string newName, int newHealth) : Enemy(newName, newHealth){
	shortsword = new MeleeWeapon ("Shortsword","Melee", 2);
}

void Goblin::attack(CombatUnit* target){
	int damage = -((Weapon*) shortsword)->getDamage();
	target->modifyHealth(damage, target);
}