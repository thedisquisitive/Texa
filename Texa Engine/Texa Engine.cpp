// Texa Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "texaLog.h"
#include "texaRoom.h"
#include "texaMap.h"
#include "texaCreature.h"

using namespace std;
using namespace Texa::World;
using namespace Texa::Entity;
using namespace Texa::Logging;

int main()
{
    TexaLogObject.initDefault();
    
    texaMap* map = new texaMap("testmap.txt");
    map->loadMap();
    
    texaCreature *player = new texaCreature("player", "Player", 100, 100, 100, 100, 10, 10, 10, 10, 10, 10, 10, map->getStartRoom());

    int running = 1;
    while (running) {
        string input;
        cout << player->getLocation()->getTitle() << endl;
        cout << player->getLocation()->getLongDescription() << endl;
        cout << "\n> ";

        cin >> input;
        if (input == "n") {
            player->moveNorth();
        }
        else if (input == "s") {
			player->moveSouth();
		}
        else if (input == "e") {
			player->moveEast();
		}
        else if (input == "w") {
			player->moveWest();
		}
        else if (input == "u") {
			player->moveUp();
		}
        else if (input == "d") {
			player->moveDown();
		}
        else if (input == "in") {
			player->moveIn();
		}
        else if (input == "out") {
			player->moveOut();
		}
        else if (input == "ne") {
			player->moveNorthEast();
		}
        else if (input == "nw") {
			player->moveNorthWest();
		}
        else if (input == "se") {
			player->moveSouthEast();
		}
        else if (input == "sw") {
			player->moveSouthWest();
		}
        else if (input == "quit") {
			running = 0;
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
