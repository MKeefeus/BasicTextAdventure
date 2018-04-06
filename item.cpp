#include "item.hpp"

Item::Item() {

}

Item::Item(std::string newName, std::string newType){
    name = newName;
    type = newType;
}

std::string Item::getName(){
    return name;
}

std::string Item::getType(){
    return type;
}