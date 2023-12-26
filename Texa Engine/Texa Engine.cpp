// Texa Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "texaLog.h"
#include "texaRoom.h"
#include "texaMap.h"

using namespace std;
using namespace Texa::World;
using Texa::Logging::TexaLogObject;

int main()
{
    TexaLogObject.initDefault();
    
    texaMap* map = new texaMap("testmap.txt");
    map->loadMap();
    Room* room = map->getStartRoom();

    cout << "\n~~~~~~~~~~~~~\n";

    cout << room->getTitle() << endl;
    cout << room->getShortDescription() << endl;

    cout << "\n~~~~Going north...\n" << endl;

    room = room->getNorth();

    cout << room->getTitle() << endl;
    cout << room->getShortDescription() << endl;

    cout << "\n~~~~Going south...\n" << endl;

    room = room->getSouth();

    cout << room->getTitle() << endl;
    cout << room->getShortDescription() << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
