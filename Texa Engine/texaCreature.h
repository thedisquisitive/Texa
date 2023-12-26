#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "texaLog.h"
#include "texaRoom.h"
#include "texaMap.h"

using namespace std;
using namespace Texa::Logging;
using namespace Texa::World;

namespace Texa {
	namespace Entity {

		class texaCreature {
			string id, name;
			int hp, maxHp, mp, maxMp, strength, dexterity, intelligence, wisdom, charisma, constitution, luck;
			texaRoom* location;
			public:
				texaCreature(string id, string name, int hp, int maxHp, int mp, int maxMp, int strength, int dexterity, int intelligence, int wisdom, int charisma, int constitution, int luck, texaRoom* location);
				~texaCreature();
				string getId();
				string getName();
				int getHp();
				int getMaxHp();
				int getMp();
				int getMaxMp();
				int getStrength();
				int getDexterity();
				int getIntelligence();
				int getWisdom();
				int getCharisma();
				int getConstitution();
				int getLuck();
				texaRoom* getLocation();
				void setId(string id);
				void setName(string name);
				void setHp(int hp);
				void setMaxHp(int maxHp);
				void setMp(int mp);
				void setMaxMp(int maxMp);
				void setStrength(int strength);
				void setDexterity(int dexterity);
				void setIntelligence(int intelligence);
				void setWisdom(int wisdom);
				void setCharisma(int charisma);
				void setConstitution(int constitution);
				void setLuck(int luck);
				void setLocation(texaRoom* location);
				void save(ofstream& file);
				void load(ifstream& file);

				void moveNorth();
				void moveSouth();
				void moveEast();
				void moveWest();
				void moveUp();
				void moveDown();
				void moveIn();
				void moveOut();
				void moveNorthEast();
				void moveNorthWest();
				void moveSouthEast();
				void moveSouthWest();

		};

	}
}