#include "enemy.hpp"
Enemy::Enemy(std::string newName, int newHealth) : CombatUnit(newName, newHealth) {
}
//Can I leave this empty and remake in base classes?
//Attacks will be different for different targets
void Enemy::attack(CombatUnit* target) {

}

std::string Enemy::getType(){
    return type;
}