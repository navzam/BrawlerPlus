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
struct Pit : public Character { Pit() : Character("Pit") {} };
struct MetaKnight : public Character { MetaKnight() : Character("Meta Knight") {} };
struct Falco : public Character { Falco() : Character("Falco") {} };
struct PokemonTrainer : public Character { PokemonTrainer() : Character("Pokemon Trainer") {} };
struct Ike : public Character { Ike() : Character("Ike") {} };
struct Snake : public Character { Snake() : Character("Snake") {} };
struct Peach : public Character { Peach() : Character("Peach") {} };
struct Yoshi : public Character { Yoshi() : Character("Yoshi") {} };
struct Ganondorf : public Character { Ganondorf() : Character("Ganondorf") {} };
struct IceClimbers : public Character { IceClimbers() : Character("Ice Climbers") {} };
struct KingDeDeDe : public Character { KingDeDeDe() : Character("King Dedede") {} };
struct Lucario : public Character { Lucario() : Character("Lucario") {} };
struct Ness : public Character { Ness() : Character("Ness") {} };
struct Sonic : public Character { Sonic() : Character("Sonic") {} };
struct Bowser : public Character { Bowser() : Character("Bowser") {} };
struct Wario : public Character { Wario() : Character("Wario") {} };
struct ToonLink : public Character { ToonLink() : Character("Toon Link") {} };
struct ROB : public Character { ROB() : Character("R.O.B.") {} };
struct Olimar : public Character { Olimar() : Character("Olimar") {} };
struct CaptainFalcon : public Character { CaptainFalcon() : Character("Captain Falcon") {} };
struct JigglyPuff : public Character { JigglyPuff() : Character("Jigglypuff") {} };
struct Lucas : public Character { Lucas() : Character("Lucas") {} };

#endif // CHARACTERS_H
