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
			vector<texaRoom*> rooms;
			public:
				texaMap(string mapFile);
				~texaMap();
				void loadMap();
				//void saveMap();
				void addRoom(texaRoom* room);
				void removeRoom(texaRoom* room);
				texaRoom* getRoom(string id);
				texaRoom* getRoom(int index);
				texaRoom* getStartRoom();
				int getRoomCount();
		};
	}

}