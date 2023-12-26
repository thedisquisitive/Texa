#include "texaRoom.h"

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "texaLog.h"

using namespace std;
using namespace Texa::Logging;

namespace Texa {
	namespace World {
		Room::Room(string id, string title, string shortDescription, string longDescription) {
			TexaLogObject << "Creating room " + id;
			this->id = id;
			this->title = title;
			this->shortDescription = shortDescription;
			this->longDescription = longDescription;
		}

		Room::~Room() {
			TexaLogObject << "Destroying room " + id;
		}

		string Room::getId() {
			return id;
		}

		string Room::getTitle() {
			return title;
		}

		string Room::getShortDescription() {
			return shortDescription;
		}

		string Room::getLongDescription() {
			return longDescription;
		}

		void Room::setNorth(Room* room) {
			north = room;
		}

		void Room::setSouth(Room* room) {
			south = room;
		}

		void Room::setEast(Room* room) {
			east = room;
		}

		void Room::setWest(Room* room) {
			west = room;
		}

		void Room::setUp(Room* room) {
			up = room;
		}

		void Room::setDown(Room* room) {
			down = room;
		}

		void Room::setIn(Room* room) {
			in = room;
		}

		void Room::setOut(Room* room) {
			out = room;
		}

		void Room::setNortheast(Room* room) {
			northeast = room;
		}

		void Room::setNorthwest(Room* room) {
			northwest = room;
		}

		void Room::setSoutheast(Room* room) {
			southeast = room;
		}

		void Room::setSouthwest(Room* room) {
			southwest = room;
		}

		Room* Room::getNorth() {
			return north;
		}

		Room* Room::getSouth() {
			return south;
		}

		Room* Room::getEast() {
			return east;
		}

		Room* Room::getWest() {
			return west;
		}

		Room* Room::getUp() {
			return up;
		}

		Room* Room::getDown() {
			return down;
		}

		Room* Room::getIn() {
			return in;
		}

		Room* Room::getOut() {
			return out;
		}

		Room* Room::getNortheast() {
			return northeast;
		}

		Room* Room::getNorthwest() {
			return northwest;
		}

		Room* Room::getSoutheast() {
			return southeast;
		}

		Room* Room::getSouthwest() {
			return southwest;
		}

		void Room::save(ofstream& file) {
			file << id << endl;
			file << title << endl;
			file << shortDescription << endl;
			file << longDescription << endl;
		}

		void Room::load(ifstream& file) {
			string tmp;
			//file >> tmp;
			int loading = 1;
			while (loading) {
				file >> tmp; 
				TexaLogObject << "\tRoom Load tmp: " + tmp;

				if (tmp == "END_ROOM")
				{
					TexaLogObject << "Finished loading room " + id;
					loading = 0;
					return;
				}
				else if (tmp == "SET") {
					string tmp2;
					file >> tmp2;
					TexaLogObject << "\t\tRoom Load tmp2: " + tmp2;
					if (tmp2 == "ROOM_TITLE") {
						getline(file, tmp2, '\"');
						getline(file, title, '\"');
						TexaLogObject << "\t\tRoom title: " + title;
					}
					else if (tmp2 == "ROOM_SHORT_DESCRIPTION") {
						getline(file, tmp2, '\"');
						getline(file, shortDescription, '\"');
						TexaLogObject << "\t\tRoom short description: " + shortDescription;
					}
					else if (tmp2 == "ROOM_LONG_DESCRIPTION") {
						getline(file, tmp2, '\"');
						getline(file, longDescription, '\"');
						TexaLogObject << "\t\tRoom long description: " + longDescription;
					}
					else if (tmp2 == "ROOM_ID") {
						getline(file, tmp2, '\"');
						getline(file, id, '\"');
						TexaLogObject << "\t\tRoom ID: " + id;
					}
					else {
						TexaLogObject << "\t\tUnknown room property " + tmp2;
					}
				}
			}
		}

	}
}