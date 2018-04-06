#include "player.hpp"
#include "potion.hpp"

//Make decision prompt in here somewhere
//What would you like to do, fight, move, search
Player::Player(std::string newName, int newHealth) : CombatUnit(newName, newHealth){
    Item* Shortsword = new MeleeWeapon("Shortsword", "Melee", 5);
    this->inventory.push_back(Shortsword);

    Item* Crossbow = new RangedWeapon("Crossbow", "Ranged", 60, 10);
    this->inventory.push_back(Crossbow);

    Spell* Firebolt = new Spell("Firebolt", "Fire", 30, 15);
    this->spellList.push_back(Firebolt);
}
void Player::addItem(Item* newItem) {
    inventory.push_back(newItem);
}

void Player::addSpell(Spell* newSpell){
    spellList.push_back(newSpell);
}

void Player::showSpells() {
    for(int i=0; i<spellList.size(); i++)
    {
        std::cout<<spellList.at(i)->getName()<<"\n";
    }
}

void Player::showPotions() {
    for(int i=0; i<inventory.size();i++){
        if(inventory.at(i)->getType()!="Ranged"&&inventory.at(i)->getType()!="Melee"){
            std::cout<<inventory.at(i)->getName();
        }
    }
}

void Player::usePotion(std::string potionToUse, Player* mainPlayer) {
    for(int i=0; i<inventory.size();i++){
        if(inventory.at(i)->getName() == potionToUse){
            int heal = ((Potion*) inventory.at(i))->getPotency();
            modifyHealth(heal, mainPlayer);
        }
    }
}

//Range needs to be implemented
void Player::castSpell(CombatUnit* target) {
    std::string spellUsed;
    bool found = false;
    while (!found){
        std::cout<< "Which spell? (type 'Check' to look at the spell list) \n";
        getline(std::cin, spellUsed);
        if(spellUsed == "Check")
        {
            this->showSpells();
        }
        else
        {
            for(int i=0; i<spellList.size(); i++){
                if(spellList.at(i)->getName() == spellUsed)
                {
                    target->modifyHealth(-(spellList.at(i)->getDamage()), target);
                    found = true;
                }
            }
            if(!found){
                std::cout<<"Spell not found, check spelling or lookup spell list \n";
            }
        }
    }
}