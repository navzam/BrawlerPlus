#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <vector>
#include "character.h"

using namespace std;

class Characters
{
    static Characters instance;
    vector<Character*> characters;
public:
    Characters();
    ~Characters();
    void registerCharacter(Character* character);
    Character* getRandom(void);
    static Characters& getInstance(void);
};

/* Mario = 0, DonkeyKong, Link, Samus, Kirby, Fox, Pikachu, Marth, MrGameAndWatch, Luigi,
		 DiddyKong, Zelda, Pit, MetaKnight, Falco, PokemonTrainer, Ike, Snake, Peach, Yoshi,
		 Ganandorf, IceClimbers, KingDeDeDe, Lucario, Ness, Sonic, Bowser, Wario, ToonLink,
		 ROB, Olimar, CaptainFalcon, JigglyPuff, Lucas */

struct Mario : public Character { Mario() : Character("Mario") {} };
struct DonkeyKong : public Character { DonkeyKong() : Character("Donkey Kong") {} };
struct Link : public Character { Link() : Character("Link") {} };

#endif // CHARACTERS_H
