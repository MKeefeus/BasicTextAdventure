#include "room.hpp"


Room::Room(std::string newName, std::string newDescription, Enemy* newEnemy, Item* newItem) {
    name = newName;
    description = newDescription;
    if(newItem != nullptr)
    {
        itemList.push_back(newItem);
    }
    else{
        delete newItem;
    }
    if(newEnemy != nullptr)
    {
        enemyList.push_back(newEnemy);
    }
    else{
        delete newEnemy;
    }
    visited = false;

}

void Room::setNorth(Room * northRoom) {
    north = northRoom;
}

void Room::setSouth(Room * southRoom) {
    south = southRoom;
}

void Room::setEast(Room * eastRoom) {
    east = eastRoom;
}

void Room::setWest(Room * westRoom) {
    west = westRoom;
}

std::string Room::getDescription() {
    return description;
}

Room* Room::getNorth() {
    return north;
}

Room* Room::getSouth() {
    return south;
}

Room* Room::getEast() {
    return east;
}

Room* Room::getWest() {
    return west;
}

std::string Room::getName() {
    return name;
}

bool Room::hasEnemies() {
    return !enemyList.empty();
}

bool Room::hasItems() {
    return !itemList.empty();
}

Enemy* Room::getEnemy() {
    return enemyList[0];
}

Item* Room::getItem() {
    return itemList[0];
}

void Room::killEnemy(Enemy* enemyToDie){
    std::cout<<enemyToDie->getName()<<" has fallen! \n";
    enemyList.erase(enemyList.begin());
}

bool Room::beenVisited() {
    return visited;
}

void Room::setVisited() {
    visited = true;
}

void Room::removeItem() {
    itemList.erase(itemList.begin());
}