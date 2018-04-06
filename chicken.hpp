#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include "enemy.hpp"

class Chicken : public Enemy{
public:
    Chicken(std::string, int);
    void obliterate(CombatUnit*);
};
#endif
