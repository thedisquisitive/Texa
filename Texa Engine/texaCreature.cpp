#include "texaCreature.h"

namespace Texa {
	namespace Entity {
		texaCreature::texaCreature(string id, string name, int hp, int maxHp, int mp, int maxMp, int strength, int dexterity, int intelligence, int wisdom, int charisma, int constitution, int luck, texaRoom* location) {
			TexaLogObject << "Creating creature " + id;
			this->id = id;
			this->name = name;
			this->hp = hp;
			this->maxHp = maxHp;
			this->mp = mp;
			this->maxMp = maxMp;
			this->strength = strength;
			this->dexterity = dexterity;
			this->intelligence = intelligence;
			this->wisdom = wisdom;
			this->charisma = charisma;
			this->constitution = constitution;
			this->luck = luck;
			this->location = location;
		}

		texaCreature::~texaCreature() {
			TexaLogObject << "Destroying creature " + id;
		}

		string texaCreature::getId() {
			return id;
		}

		string texaCreature::getName() {
			return name;
		}

		int texaCreature::getHp() {
			return hp;
		}

		int texaCreature::getMaxHp() {
			return maxHp;
		}

		int texaCreature::getMp() {
			return mp;
		}

		int texaCreature::getMaxMp() {
			return maxMp;
		}

		int texaCreature::getStrength() {
			return strength;
		}

		int texaCreature::getDexterity() {
			return dexterity;
		}

		int texaCreature::getIntelligence() {
			return intelligence;
		}

		int texaCreature::getWisdom() {
			return wisdom;
		}

		int texaCreature::getCharisma() {
			return charisma;
		}

		int texaCreature::getConstitution() {
			return constitution;
		}

		int texaCreature::getLuck() {
			return luck;
		}

		texaRoom* texaCreature::getLocation() {
			return location;
		}

		void texaCreature::setId(string id) {
			this->id = id;
		}

		void texaCreature::setName(string name) {
			this->name = name;
		}

		void texaCreature::setHp(int hp) {
			this->hp = hp;
		}

		void texaCreature::setMaxHp(int maxHp) {
			this->maxHp = maxHp;
		}

		void texaCreature::setMp(int mp) {
			this->mp = mp;
		}

		void texaCreature::setMaxMp(int maxMp) {
			this->maxMp = maxMp;
		}

		void texaCreature::setStrength(int strength) {
			this->strength = strength;
		}

		void texaCreature::setDexterity(int dexterity) {
			this->dexterity = dexterity;
		}

		void texaCreature::setIntelligence(int intelligence) {
			this->intelligence = intelligence;
		}

		void texaCreature::setWisdom(int wisdom) {
			this->wisdom = wisdom;
		}

		void texaCreature::setCharisma(int charisma) {
			this->charisma = charisma;
		}

		void texaCreature::setConstitution(int constitution) {
			this->constitution = constitution;
		}

		void texaCreature::setLuck(int luck) {
			this->luck = luck;
		}

		void texaCreature::setLocation(texaRoom* location) {
			this->location = location;
		}

		void texaCreature::save(ofstream& file) {
			file << id << endl;
			file << name << endl;
			file << hp << endl;
			file << maxHp << endl;
			file << mp << endl;
			file << maxMp << endl;
			file << strength << endl;
			file << dexterity << endl;
			file << intelligence << endl;
			file << wisdom << endl;
			file << charisma << endl;
			file << constitution << endl;
			file << luck << endl;
			file << location->getId() << endl;
		}

		void texaCreature::load(ifstream& file) {
			string tmp;
			file >> tmp;
			id = tmp;
			file >> tmp;
			name = tmp;
			file >> tmp;
			hp = stoi(tmp);
			file >> tmp;
			maxHp = stoi(tmp);
			file >> tmp;
			mp = stoi(tmp);
			file >> tmp;
			maxMp = stoi(tmp);
			file >> tmp;
			strength = stoi(tmp);
			file >> tmp;
			dexterity = stoi(tmp);
			file >> tmp;
			intelligence = stoi(tmp);
			file >> tmp;
			wisdom = stoi(tmp);
			file >> tmp;
			charisma = stoi(tmp);
			file >> tmp;
			constitution = stoi(tmp);
			file >> tmp;
			luck = stoi(tmp);
			file >> tmp;
		}

		void texaCreature::moveNorth() {
			if (location->getNorth() != NULL) {
				location = location->getNorth();
			}
			else {
				cout << "You can't find any way to go north." << endl;
				return;
			}
		}

		void texaCreature::moveSouth() {
			if (location->getSouth() != NULL) {
				location = location->getSouth();
			}
			else {
				cout << "You can't find any way to go south." << endl;
				return;
			}
		}

		void texaCreature::moveEast() {
			if (location->getEast() != NULL) {
				location = location->getEast();
			}
			else {
				cout << "You can't find any way to go east." << endl;
				return;
			}
		}

		void texaCreature::moveWest() {
			if (location->getWest() != NULL) {
				location = location->getWest();
			}
			else {
				cout << "You can't find any way to go west." << endl;
				return;
			}
		}

		void texaCreature::moveDown() {
			if (location->getDown() != NULL) {
				location = location->getWest();
			}
			else {
				cout << "You can't find any way to go down." << endl;
				return;
			}
		}

		void texaCreature::moveUp() {
			if (location->getUp() != NULL) {
				location = location->getUp();
			}
			else {
				cout << "You can't find any way to go up." << endl;
				return;
			}
		}

		void texaCreature::moveNorthEast() {
			if (location->getNortheast() != NULL) {
				location = location->getNortheast();
			}
			else {
				cout << "You can't find any way to go northeast." << endl;
				return;
			}
		}

		void texaCreature::moveNorthWest() {
			if (location->getNorthwest() != NULL) {
				location = location->getNorthwest();
			}
			else {
				cout << "You can't find any way to go northwest." << endl;
				return;
			}
		}

		void texaCreature::moveSouthEast() {
			if (location->getSoutheast() != NULL) {
				location = location->getSoutheast();
			}
			else {
				cout << "You can't find any way to go southeast." << endl;
				return;
			}
		}

		void texaCreature::moveSouthWest() {
			if (location->getSouthwest() != NULL) {
				location = location->getSouthwest();
			}
			else {
				cout << "You can't find any way to go southwest." << endl;
				return;
			}
		}

		void texaCreature::moveOut() {
			if (location->getOut() != NULL) {
				location = location->getOut();
			}
			else {
				cout << "You can't find any way to go out." << endl;
				return;
			}
		}

		void texaCreature::moveIn() {
			if (location->getIn() != NULL) {
				location = location->getIn();
			}
			else {
				cout << "You can't find any way to go in." << endl;
				return;
			}
		}
	}
}