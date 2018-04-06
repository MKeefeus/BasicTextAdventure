#ifndef COMBAT_UNIT
#define COMBAT_UNIT

#include "melee.hpp"
#include "ranged.hpp"
class CombatUnit{
public:
    CombatUnit();
    CombatUnit(std::string, int);
    int getHealth();
    void modifyHealth(int, CombatUnit*);
    void showInventory();
    virtual void attack(CombatUnit*);
    std::string getName();
protected:
    int health;
    std::string name;
    std::vector<Item*> inventory;
};
#endif
