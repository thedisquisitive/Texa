#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "texaLog.h"

using namespace std;

namespace Texa {
	namespace World {

		class texaRoom {
		private:
			string id, title, shortDescription, longDescription;
			texaRoom *north, *south, *east, *west, *up, *down, *in, *out, *northeast, *northwest, *southeast, *southwest;
		public:
			texaRoom(string id, string title, string shortDescription, string longDescription);
			~texaRoom();
			string getId();
			string getTitle();
			string getShortDescription();
			string getLongDescription();
			void setNorth(texaRoom *room);
			void setSouth(texaRoom *room);
			void setEast(texaRoom *room);
			void setWest(texaRoom *room);
			void setUp(texaRoom *room);
			void setDown(texaRoom *room);
			void setIn(texaRoom *room);
			void setOut(texaRoom *room);
			void setNortheast(texaRoom *room);
			void setNorthwest(texaRoom *room);
			void setSoutheast(texaRoom *room);
			void setSouthwest(texaRoom *room);
			texaRoom *getNorth();
			texaRoom *getSouth();
			texaRoom *getEast();
			texaRoom *getWest();
			texaRoom *getUp();
			texaRoom *getDown();
			texaRoom *getIn();
			texaRoom *getOut();
			texaRoom *getNortheast();
			texaRoom *getNorthwest();
			texaRoom *getSoutheast();
			texaRoom *getSouthwest();

			void save(ofstream &file);
			void load(ifstream &file);

		};

	}
}