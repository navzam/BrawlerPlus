#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "QString"

enum Character {Mario = 0, DonkeyKong, Link, Samus, Kirby, Fox, Pikachu, Marth, MrGameAndWatch, Luigi,
                 DiddyKong, Zelda, Pit, MetaKnight, Falco, PokemonTrainer, Ike, Snake, Peach, Yoshi,
                 Ganandorf, IceClimbers, KingDeDeDe, Lucario, Ness, Sonic, Bowser, Wario, ToonLink,
                 ROB, Olimar, CaptainFalcon, JigglyPuff, Lucas};

Character randomCharacter()
{
    Character character = (Character)(rand() % 35);
    return character;
}

QString characterToString(Character character)
{
    switch(character)
    {
    case Mario:
        return "Mario";
    case DonkeyKong:
        return "Donkey Kong";
    case Link:
        return "Link";
    case Samus:
        return "Samus";
    case Kirby:
        return "Kirby";
    case Fox:
        return "Fox";
    case Pikachu:
        return "Pikachu";
    case Marth:
        return "Marth";
    case MrGameAndWatch:
        return "Mr. Game and Watch";
    case Luigi:
        return "Luigi";
    case DiddyKong:
        return "Diddy Kong";
    case Zelda:
        return "Zelda";
    case Pit:
        return "Pit";
    case MetaKnight:
        return "Meta Knight";
    case Falco:
        return "Falco";
    case PokemonTrainer:
        return "Pokemon Trainer";
    case Ike:
        return "Ike";
    case Snake:
        return "Snake";
    case Peach:
        return "Peach";
    case Yoshi:
        return "Yoshi";
    case Ganandorf:
        return "Ganandorf";
    case IceClimbers:
        return "Ice Climbers";
    case KingDeDeDe:
        return "King DeDeDe";
    case Lucario:
        return "Lucario";
    case Ness:
        return "Ness";
    case Sonic:
        return "Sonic";
    case Bowser:
        return "Bowser";
    case Wario:
        return "Wario";
    case ToonLink:
        return "Toon Link";
    case ROB:
        return "ROB";
    case Olimar:
        return "Olimar";
    case CaptainFalcon:
        return "Captain Falcon";
    case JigglyPuff:
        return "Jigglypuff";
    case Lucas:
        return "Lucas";
    }
}

#endif // CHARACTERS_H
