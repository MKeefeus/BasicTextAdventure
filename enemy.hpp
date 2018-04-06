#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "combatunit.hpp"
class Enemy : public CombatUnit{

public:
	Enemy(std::string, int);
	std::string getType();
    virtual void attack(CombatUnit*);

protected:
	std::string type;
};


#endif
