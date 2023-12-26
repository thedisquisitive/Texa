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
		texaRoom::texaRoom(string id, string title, string shortDescription, string longDescription) {
			TexaLogObject << "Creating room " + id;
			this->id = id;
			this->title = title;
			this->shortDescription = shortDescription;
			this->longDescription = longDescription;
		}

		texaRoom::~texaRoom() {
			TexaLogObject << "Destroying room " + id;
		}

		string texaRoom::getId() {
			return id;
		}

		string texaRoom::getTitle() {
			return title;
		}

		string texaRoom::getShortDescription() {
			return shortDescription;
		}

		string texaRoom::getLongDescription() {
			return longDescription;
		}

		void texaRoom::setNorth(texaRoom* room) {
			north = room;
		}

		void texaRoom::setSouth(texaRoom* room) {
			south = room;
		}

		void texaRoom::setEast(texaRoom* room) {
			east = room;
		}

		void texaRoom::setWest(texaRoom* room) {
			west = room;
		}

		void texaRoom::setUp(texaRoom* room) {
			up = room;
		}

		void texaRoom::setDown(texaRoom* room) {
			down = room;
		}

		void texaRoom::setIn(texaRoom* room) {
			in = room;
		}

		void texaRoom::setOut(texaRoom* room) {
			out = room;
		}

		void texaRoom::setNortheast(texaRoom* room) {
			northeast = room;
		}

		void texaRoom::setNorthwest(texaRoom* room) {
			northwest = room;
		}

		void texaRoom::setSoutheast(texaRoom* room) {
			southeast = room;
		}

		void texaRoom::setSouthwest(texaRoom* room) {
			southwest = room;
		}

		texaRoom* texaRoom::getNorth() {
			return north;
		}

		texaRoom* texaRoom::getSouth() {
			return south;
		}

		texaRoom* texaRoom::getEast() {
			return east;
		}

		texaRoom* texaRoom::getWest() {
			return west;
		}

		texaRoom* texaRoom::getUp() {
			return up;
		}

		texaRoom* texaRoom::getDown() {
			return down;
		}

		texaRoom* texaRoom::getIn() {
			return in;
		}

		texaRoom* texaRoom::getOut() {
			return out;
		}

		texaRoom* texaRoom::getNortheast() {
			return northeast;
		}

		texaRoom* texaRoom::getNorthwest() {
			return northwest;
		}

		texaRoom* texaRoom::getSoutheast() {
			return southeast;
		}

		texaRoom* texaRoom::getSouthwest() {
			return southwest;
		}

		void texaRoom::save(ofstream& file) {
			file << id << endl;
			file << title << endl;
			file << shortDescription << endl;
			file << longDescription << endl;
		}

		void texaRoom::load(ifstream& file) {
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