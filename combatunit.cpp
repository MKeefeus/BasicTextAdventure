#include "combatunit.hpp"

CombatUnit::CombatUnit() {

}

CombatUnit::CombatUnit(std::string newName, int newHealth) {
    health = newHealth;
    name = newName;
}
void CombatUnit::modifyHealth(int displacement, CombatUnit* target) {
    name = target->getName();
    health = health + displacement;
    if(target->getHealth()<1 && target->getName() =="You")
    {
        std::cout<<"You have fallen :(\n";
        return;
    }
    else {
        if (name == "You") {
            std::cout << name << " have " << health << " health left\n";
        } else {
            std::cout << name << " has " << health << " health left\n";
        }
    }
}

int CombatUnit::getHealth() {
    return health;
}

void CombatUnit::showInventory() {
    for(int i=0; i<inventory.size(); i++){
        if(inventory.at(i)->getType()!="Potion") {
            std::cout << inventory.at(i)->getName() << "\n";
        }
    }
}

std::string CombatUnit::getName() {
    return name;
}

//Make virtual, rewrite without prompts in enemy class
void CombatUnit::attack(CombatUnit* target) {
    std::string weaponName;
    bool found = false;
    while (!found) {
        std::cout << "which weapon? (type 'Check' to look at inventory) \n";
        getline(std::cin, weaponName);
        if(weaponName == "Check")
        {
            this->showInventory();
        }
        else
        {
            for (int i = 0; i < inventory.size(); i++) {
                if (inventory.at(i)->getName() == weaponName) {
                    target->modifyHealth(-((Weapon*) inventory.at(i))->getDamage(), target);
                    found = true;
                }
            }
            if (!found) {
                std::cout << "Item not found, check spelling or lookup inventory \n";
            }
        }
    }
}