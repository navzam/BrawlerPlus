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
struct Samus : public Character { Samus() : Character("Samus") {} };
struct Kirby : public Character { Kirby() : Character("Kirby") {} };
struct Fox : public Character { Fox() : Character("Fox") {} };
struct Pikachu : public Character { Pikachu() : Character("Pikachu") {} };
struct Marth : public Character { Marth() : Character("Marth") {} };
struct MrGameAndWatch : public Character { MrGameAndWatch() : Character("Mr. Game & Watch") {} };
struct Luigi : public Character { Luigi() : Character("Luigi") {} };
struct DiddyKong : public Character { DiddyKong() : Character("Diddy Kong") {} };
struct Zelda : public Character { Zelda() : Character("Zelda") {} };

#endif // CHARACTERS_H
