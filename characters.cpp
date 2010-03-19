#include "characters.h"
#include <ctime>

Characters Characters::instance;

Characters::Characters()
{
    srand(time(NULL));
    new Mario();
    new DonkeyKong();
    new Link();
    new Samus();
    new Kirby();
    new Fox();
    new Pikachu();
    new Marth();
    new MrGameAndWatch();
    new Luigi();
    new DiddyKong();
    new Zelda();
    new Pit();
    new MetaKnight();
    new Falco();
    new PokemonTrainer();
    new Ike();
    new Snake();
    new Peach();
    new Yoshi();
    new Ganondorf();
    new IceClimbers();
    new KingDeDeDe();
    new Lucario();
    new Ness();
    new Sonic();
    new Bowser();
    new Wario();
    new ToonLink();
    new ROB();
    new Olimar();
    new CaptainFalcon();
    new JigglyPuff();
    new Lucas();
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
