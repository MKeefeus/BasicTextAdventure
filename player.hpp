#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "combatunit.hpp"
#include "spells.hpp"
#include "melee.hpp"
#include "ranged.hpp"

class Player : public CombatUnit{

public:

    Player(std::string, int);
    void addItem(Item*);
    void addSpell(Spell*);
    void showSpells();
    void showPotions();
    void usePotion(std::string, Player*);
    void castSpell(CombatUnit*);

private:
    std::vector<Spell*> spellList;
};


#endif
