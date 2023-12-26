#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "texaLog.h"
#include "texaRoom.h"

using namespace std;
using namespace Texa::Logging;

namespace Texa {
	namespace World {
		class texaMap {
			string mapFile, mapName, mapAuthor, mapDescription, startRoom;
			vector<Room*> rooms;
			public:
				texaMap(string mapFile);
				~texaMap();
				void loadMap();
				//void saveMap();
				void addRoom(Room* room);
				void removeRoom(Room* room);
				Room* getRoom(string id);
				Room* getRoom(int index);
				Room* getStartRoom();
				int getRoomCount();
		};
	}

}