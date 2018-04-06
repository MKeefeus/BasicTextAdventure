#ifndef ORC_HPP
#define ORC_HPP

#include "enemy.hpp"

class Orc: public Enemy{
public:
    Orc(std::string, int);
    void attack(CombatUnit*);

private:
    Item* Greataxe;
};
#endif
