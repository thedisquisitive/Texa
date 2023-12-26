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
    TexaLogObject << "Initiated TexaLogObject";
    Room *room = new Room("ROOM1", "Generic Room", "Thy trusty generic room.", "A rather generic room. Even by generic room standards, this is generic.");
    Room *room2 = new Room("ROOM2", "Generic Room 2", "Thy trusty generic room. Part deux.", "A rather generic room. Part deux.\nEven compared to the first room, this is generic.");
    room->setNorth(room2);

    Room *current_room = room;
    TexaLogObject << "Current room: " + current_room->getTitle();
    TexaLogObject << "Current room description: " + current_room->getShortDescription();
	TexaLogObject << "Current room long description: " + current_room->getLongDescription();
    TexaLogObject << "\n\nGoing north...\n\n";
    current_room = current_room->getNorth();
    TexaLogObject << "Current room: " + current_room->getTitle();
    TexaLogObject << "Current room description: " + current_room->getShortDescription();
    TexaLogObject << "Current room long description: " + current_room->getLongDescription();

    delete room, room2;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
