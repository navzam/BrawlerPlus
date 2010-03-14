#include "characters.h"
#include <cstdlib>
#include <ctime>

Characters Characters::instance;

Characters::Characters()
{
    srand(time(NULL));
    new Mario();
    new DonkeyKong();
    new Link();
}

Characters::~Characters()
{
    for(vector<Character*>::iterator it = characters.begin(); it != characters.end(); ++it)
    {
	delete *it;
    }
}

void Characters::registerCharacter(Character* character)
{
    characters.push_back(character);
}

Character* Characters::getRandom(void)
{
    return characters.at(rand() % characters.size());
}

Characters& Characters::getInstance(void)
{
    return instance;
}
