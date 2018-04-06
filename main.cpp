//Give player a name and have modify health distinguish between units


#include "goblin.hpp"
#include "player.hpp"
#include "room.hpp"
#include "potion.hpp"
#include "orc.hpp"
#include "chicken.hpp"

void playerChoice(Room*, Player*);
void connectRooms(std::vector<Room*>*);

int main() {
    std::cout<<"\nWelcome to the game! Please capitalize your inputs and have fun! Type 'End' to quit at any time.\n\n";
    Player* mainPlayer = new Player("You", 100);
    Goblin* frontGuard = new Goblin("Goblin", 25);
    Goblin* hallGuard = new Goblin("Goblin", 10);
    Orc* blacksmith = new Orc("Orc", 35);
    Chicken* almightyOverlord = new Chicken("Chicken", 500);
    Item* greaterHealthPotion = new Potion("Greater Healing Potion", "Potion", "Heals you", 25);
    Item* greataxxe = new MeleeWeapon("Greataxe", "Melee", 15);
    std::vector<Room*> roomList;
    roomList.push_back(new Room("The Front Room:", "You enter to a dimly lit room, in its center you see an armed goblin guarding a door to the north \n", frontGuard, nullptr));
    roomList.push_back(new Room("The Great Hall:","This room is brightly lit. The main hall of this area, this wide room has an east and west door, as well as a chest in its center\n", nullptr, greaterHealthPotion));
    roomList.push_back(new Room("The West Hallway:", "The hallway has beautiful stained glass on its west side overviewing the mountains. There are no people in this room but you hear something coming from the north\n", nullptr, nullptr));
    roomList.push_back(new Room("The Armory:","In this room you see a 6 foot orc working a forge. He turns angrily at your intrusion, this seems to be the only way in or out\n", blacksmith, greataxxe));
    roomList.push_back(new Room("The East Hallway:", "This hallway is a barely lit stone hallway, in the hallway is another goblin blocking your path to the north door\n", hallGuard,nullptr));
    roomList.push_back(new Room("The Library:", "You enter into a vast library. All its shelves have been emptied, but there is a stairway to the west\n", nullptr, nullptr));
    roomList.push_back(new Room("The Stairwell:", "The stairs are nearly pitch black, the only light emanates from the very top to the north where you hear something, but can not tell what\n", nullptr,nullptr));
    roomList.push_back(new Room("The Throne Room:", "Finally reaching the top of the stairs you see an eloquent throne. Perched in its velvet seat is a simple chicken\n", almightyOverlord, nullptr));

    connectRooms(&roomList);
    Room* currRoom = roomList[0];
    currRoom->setVisited();
    std::cout<<currRoom->getDescription();
    playerChoice(currRoom, mainPlayer);

}

void connectRooms(std::vector<Room*>* roomList){
    roomList->at(0)->setNorth(roomList->at(1));
    roomList->at(1)->setSouth(roomList->at(0));
    roomList->at(1)->setWest(roomList->at(2));
    roomList->at(2)->setEast(roomList->at(1));
    roomList->at(2)->setNorth(roomList->at(3));
    roomList->at(3)->setSouth(roomList->at(2));
    roomList->at(1)->setEast(roomList->at(4));
    roomList->at(4)->setWest(roomList->at(1));
    roomList->at(4)->setNorth(roomList->at(5));
    roomList->at(5)->setSouth(roomList->at(4));
    roomList->at(5)->setWest(roomList->at(6));
    roomList->at(6)->setEast(roomList->at(5));
    roomList->at(6)->setNorth(roomList->at(7));
    roomList->at(7)->setSouth(roomList->at(6));



}

void playerChoice(Room *currRoom, Player* mainPlayer) {
    std::string choiceInput;
    while(true) {
        if (currRoom->getName() == "The Throne Room:") {
            bool theEnd = false;
            std::cout << "Do you want to Befriend or Attack the chicken?\n";
            while (!theEnd) {
                getline(std::cin, choiceInput);
                if (choiceInput == "Attack") {
                    ((Chicken *) currRoom->getEnemy())->obliterate(mainPlayer);
                    std::cout << "Thanks for playing!\n";
                    return;
                } else {
                    std::cout << "You make friends with a chicken, and you both live happily ever after\n";
                    std::cout << "Thanks for playing!\n";
                    return;
                }
            }
        } else {
            bool enemies = currRoom->hasEnemies();
            bool items = currRoom->hasItems();
            if (enemies) {
                std::cout << "Would you like to Attack, Search, Use an item, or Move? \n";
            } else {
                std::cout << "Would you like to Search, Use an item, or Move? \n";
            }
            getline(std::cin, choiceInput);
            if (choiceInput == "End") {
                std::cout << "Thanks for playing!\n";
                return;
            } else if (choiceInput == "Attack") {
                Enemy *target = currRoom->getEnemy();
                while (target->getHealth() > 0) {
                    std::cout << "Weapon or Spell? \n";
                    getline(std::cin, choiceInput);
                    if (choiceInput == "Spell") {
                        mainPlayer->castSpell(target);
                    } else if (choiceInput == "Weapon") {
                        mainPlayer->attack(target);
                    } else {
                        continue;
                    }
                    if (target->getHealth() < 1) {
                        currRoom->killEnemy(target);
                    } else {
                        std::cout << "The " << target->getName() << " attacks you!\n";
                        target->attack(mainPlayer);
                    }
                    if (mainPlayer->getHealth() < 1) {
                        return;
                    }
                }
            } else if (choiceInput == "Search") {
                if (currRoom->hasEnemies()) {
                    std::cout << "The " << (currRoom->getEnemy())->getName() << " is blocking your search! \n";
                } else if (currRoom->hasItems()) {
                    std::cout << "You found a " << (currRoom->getItem())->getName() << "\n";
                    mainPlayer->addItem(currRoom->getItem());
                    currRoom->removeItem();
                } else {
                    std::cout << "You don't find anything of interest \n";
                }
            } else if(choiceInput == "Use an item"){
                std::cout<<"Which item? (type 'Check' to view items)\n";
                getline(std::cin, choiceInput);
                if(choiceInput == "Check"){
                    mainPlayer->showPotions();
                    std::cout<<"Which item\n";
                    getline(std::cin, choiceInput);
                    mainPlayer->usePotion(choiceInput, mainPlayer);
                }
                else{
                    mainPlayer->usePotion(choiceInput, mainPlayer);
                }
            } else if (choiceInput == "Move") {
                if (currRoom->hasEnemies()) {
                    std::cout << "The " << (currRoom->getEnemy())->getName() << " is blocking your movement! \n";
                } else {
                    bool fuckup = true;
                    while (fuckup) {
                        std::cout << "North, South, East, or West \n";
                        getline(std::cin, choiceInput);
                        if (choiceInput == "North" && currRoom->getNorth()) {
                            currRoom = currRoom->getNorth();
                            if (currRoom->beenVisited()) {
                                std::cout << "You've returned to the " << currRoom->getName() << "\n";
                            } else {
                                std::cout << currRoom->getName() << " " << currRoom->getDescription() << "\n";
                                currRoom->setVisited();
                            }
                            fuckup = false;
                        } else if (choiceInput == "South" && currRoom->getSouth()) {
                            currRoom = currRoom->getSouth();
                            if (currRoom->beenVisited()) {
                                std::cout << "You've returned to the " << currRoom->getName() << "\n";
                            } else {
                                std::cout << currRoom->getName() << " " << currRoom->getDescription() << "\n";
                                currRoom->setVisited();
                            }
                            fuckup = false;
                        } else if (choiceInput == "East" && currRoom->getEast()) {
                            currRoom = currRoom->getEast();
                            if (currRoom->beenVisited()) {
                                std::cout << "You've returned to the " << currRoom->getName() << "\n";
                            } else {
                                std::cout << currRoom->getName() << " " << currRoom->getDescription() << "\n";
                                currRoom->setVisited();
                            }
                            fuckup = false;
                        } else if (choiceInput == "West" && currRoom->getWest()) {
                            currRoom = currRoom->getWest();
                            if (currRoom->beenVisited()) {
                                std::cout << "You've returned to the " << currRoom->getName() << "\n";
                            } else {
                                std::cout << currRoom->getName() << " " << currRoom->getDescription() << "\n";
                                currRoom->setVisited();
                            }
                            fuckup = false;
                        } else if (choiceInput != "North" && choiceInput != "South" && choiceInput != "East" &&
                                   choiceInput != "West") {
                            std::cout << "Check your spelling/capitalization\n";
                        } else {
                            std::cout << currRoom->getName() << " does not have a room to its " << choiceInput
                                      << "! Please select a different direction \n";
                        }
                    }
                }
            }
        }
    }
}
