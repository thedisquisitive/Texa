#include "texaMap.h"

namespace Texa {
	namespace World {
		texaMap::texaMap(string mapFile) {
			this->mapFile = mapFile;
			TexaLogObject << "Creating map from " + mapFile;
		}
		texaMap::~texaMap() {
			TexaLogObject << "Destroying map " + mapFile;
			for (int i = 0; i < rooms.size(); i++) {
				delete rooms[i];
			}
		}
		void texaMap::loadMap() {
			ifstream fin(mapFile.c_str());
			if (!fin) {
				TexaLogObject << "Error loading map " + mapFile;
				return;
			}
			string command;
			int loading = 1;
			while (loading) {
				fin >> command;
				if (command[0] == '#') { // Commented line
					getline(fin, command, '\n');
					continue;
				}
				if (command == "END_MAP") { // Stop loading map
					TexaLogObject << "Finished loading map " + mapFile;
					loading = 0;
					break;
				}
				else if (command == "SET") { // Set map properties
					string tmp;
					fin >> tmp;
					if (tmp == "MAP_NAME") {
						getline(fin, tmp, '\"');
						getline(fin, mapName, '\"');
						TexaLogObject << "Map name: " + mapName;
					}
					else if (tmp == "MAP_AUTHOR") {
						getline(fin, tmp, '\"');
						getline(fin, mapAuthor, '\"');
						TexaLogObject << "Map author: " + mapAuthor;
					}
					else if (tmp == "MAP_DESCRIPTION") {
						getline(fin, tmp, '\"');
						getline(fin, mapDescription, '\"');
						TexaLogObject << "Map description: " + mapDescription;
					}
					else if (tmp == "START_ROOM") {
						getline(fin, tmp, '\"');
						getline(fin, startRoom, '\"');
						TexaLogObject << "Start room: " + startRoom;
					}
					else {
						TexaLogObject << "Unknown map property " + tmp;
					}
				}
				else if (command == "ROOM") { // Create a room
					texaRoom* room = new texaRoom("", "", "", "");
					room->load(fin);
					addRoom(room);
					TexaLogObject << "Loaded room " + room->getId();
				}
				else if (command == "LINK") { // Link rooms
					string room1, room2, direction, tmp;
					getline(fin, tmp, '\"');
					getline(fin, room1, '\"');
					getline(fin, tmp, '\"');
					getline(fin, room2, '\"');
					getline(fin, tmp, '\"');
					getline(fin, direction, '\"');

					TexaLogObject << "Linking room " + room2 + " to room " + room1 + " in direction " + direction;

					if (direction == "NORTH") {
						getRoom(room1)->setNorth(getRoom(room2));
						getRoom(room2)->setSouth(getRoom(room1));
					}
					else if (direction == "SOUTH") {
						getRoom(room1)->setSouth(getRoom(room2));
						getRoom(room2)->setNorth(getRoom(room1));
					}
					else if (direction == "EAST") {
						getRoom(room1)->setEast(getRoom(room2));
						getRoom(room2)->setWest(getRoom(room1));
					}
					else if (direction == "WEST") {
						getRoom(room1)->setWest(getRoom(room2));
						getRoom(room2)->setEast(getRoom(room1));
					}
					else if (direction == "UP") {
						getRoom(room1)->setUp(getRoom(room2));
						getRoom(room2)->setDown(getRoom(room1));
					}
					else if (direction == "DOWN") {
						getRoom(room1)->setDown(getRoom(room2));
						getRoom(room2)->setUp(getRoom(room1));
					}
					else if (direction == "NORTHEAST") {
						getRoom(room1)->setNortheast(getRoom(room2));
						getRoom(room2)->setSouthwest(getRoom(room1));
					}
					else if (direction == "NORTHWEST") {
						getRoom(room1)->setNorthwest(getRoom(room2));
						getRoom(room2)->setSoutheast(getRoom(room1));
					}
					else if (direction == "SOUTHEAST") {
						getRoom(room1)->setSoutheast(getRoom(room2));
						getRoom(room2)->setNorthwest(getRoom(room1));
					}
					else if (direction == "SOUTHWEST") {
						getRoom(room1)->setSouthwest(getRoom(room2));
						getRoom(room2)->setNortheast(getRoom(room1));
					}
					else if (direction == "IN") {
						getRoom(room1)->setIn(getRoom(room2));
						getRoom(room2)->setOut(getRoom(room1));
					}
					else if (direction == "OUT") {
						getRoom(room1)->setOut(getRoom(room2));
						getRoom(room2)->setIn(getRoom(room1));
					}
					else {
						TexaLogObject << "Unknown direction " + direction;
					}
				}
				else {
					TexaLogObject << "Unknown command " + command;
				}
			}
		}

		void texaMap::addRoom(texaRoom* room) {
			rooms.push_back(room);
		}

		void texaMap::removeRoom(texaRoom* room) {
			for (int i = 0; i < rooms.size(); i++) {
				if (rooms[i] == room) {
					rooms.erase(rooms.begin() + i);
					break;
				}
			}
		}

		texaRoom* texaMap::getRoom(string id) {
			for (int i = 0; i < rooms.size(); i++) {
				if (rooms[i]->getId() == id) {
					return rooms[i];
				}
			}
			return NULL;
		}

		texaRoom* texaMap::getRoom(int index) {
			return rooms[index];
		}

		int texaMap::getRoomCount() {
			return rooms.size();
		}

		texaRoom* texaMap::getStartRoom() {
			return getRoom(startRoom);
		}
	}
}