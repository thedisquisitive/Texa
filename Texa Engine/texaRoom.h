#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "texaLog.h"

using namespace std;

namespace Texa {
	namespace World {

		class Room {
		private:
			string id, title, shortDescription, longDescription;
			Room *north, *south, *east, *west, *up, *down, *in, *out, *northeast, *northwest, *southeast, *southwest;
		public:
			Room(string id, string title, string shortDescription, string longDescription);
			~Room();
			string getId();
			string getTitle();
			string getShortDescription();
			string getLongDescription();
			void setNorth(Room *room);
			void setSouth(Room *room);
			void setEast(Room *room);
			void setWest(Room *room);
			void setUp(Room *room);
			void setDown(Room *room);
			void setIn(Room *room);
			void setOut(Room *room);
			void setNortheast(Room *room);
			void setNorthwest(Room *room);
			void setSoutheast(Room *room);
			void setSouthwest(Room *room);
			Room *getNorth();
			Room *getSouth();
			Room *getEast();
			Room *getWest();
			Room *getUp();
			Room *getDown();
			Room *getIn();
			Room *getOut();
			Room *getNortheast();
			Room *getNorthwest();
			Room *getSoutheast();
			Room *getSouthwest();

			void save(ofstream &file);
			void load(ifstream &file);

		};

	}
}