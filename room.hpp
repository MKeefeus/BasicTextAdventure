#ifndef ROOM_HPP
#define ROOM_HPP

#include "iostream"
#include "goblin.hpp"
#include "melee.hpp"
#include "ranged.hpp"


/* Needs to have enemies and items
 *
*/
class Room{
public:
    Room(std::string, std::string, Enemy*, Item*);
    void setNorth(Room*);
    void setSouth(Room*);
    void setEast(Room*);
    void setWest(Room*);
    bool hasEnemies();
    bool hasItems();
    bool beenVisited();
    void setVisited();
    void removeItem();
    std::string getDescription();
    std::string getName();
    Enemy* getEnemy();
    Item* getItem();
    void killEnemy(Enemy*);
    Room* getNorth();
    Room* getSouth();
    Room* getEast();
    Room* getWest();
private:
    bool visited;
    std::string name;
    std::string description;
    Room* north;
    Room* south;
    Room* east;
    Room* west;
    std::vector<Enemy*> enemyList;
    std::vector<Item*> itemList;
};

#endif
