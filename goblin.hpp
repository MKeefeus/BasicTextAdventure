#ifndef GOBLIN_HPP
#define GOBLIN_HPP
#include "enemy.hpp"

class Goblin : public Enemy{

public:
	Goblin(std::string, int);
    void attack(CombatUnit*);

private:
    Item* shortsword;
};

#endif