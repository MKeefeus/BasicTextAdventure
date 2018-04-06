//
// Created by malcolm on 3/22/18.
//

#ifndef POTION_HPP
#define POTION_HPP

#include "item.hpp"

class Potion : public Item{
public:
    Potion(std::string, std::string, std::string, int);
    void getDescrption();
    int getPotency();

private:
    std::string description;
    int potency;
};
#endif
