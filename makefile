all: textadventure

textadventure: combatunit.cpp enemy.cpp goblin.cpp item.cpp main.cpp melee.cpp orc.cpp player.cpp potion.cpp ranged.cpp room.cpp spells.cpp weapon.cpp chicken.cpp
	g++ combatunit.cpp enemy.cpp goblin.cpp item.cpp main.cpp melee.cpp orc.cpp player.cpp potion.cpp ranged.cpp room.cpp spells.cpp weapon.cpp chicken.cpp -std=c++11 -o TextAdventure