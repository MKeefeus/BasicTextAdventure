#include "chicken.hpp"

Chicken::Chicken(std::string newName, int newHealth) : Enemy(newName, newHealth){
    health = newHealth;
    name = newName;
}

void Chicken::obliterate(CombatUnit * poorBastard) {
    std::cout<<"You witness the chicken begin to shake violently. In an instant, a fiery explosion expands from the chicken.\nYou are knocked onto your back as you see the building begin to collapse around you. You try to run but your legs are too damaged from the blast.\nThe last thing you see is the ceiling fall onto you, before ever consuming darkness\n";
    poorBastard->modifyHealth(-5000, poorBastard);
}