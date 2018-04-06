#include "potion.hpp"

Potion::Potion(std::string newName, std::string newType, std::string newDescription, int newPotency) : Item(newName, newType){
    description = newDescription;
    potency = newPotency;
}

void Potion::getDescrption() {
    std::cout<<description<<"\n";
}

int Potion::getPotency() {
    return potency;
}