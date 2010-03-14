#ifndef PLAYER_H
#define PLAYER_H

#include "string"
#include "Savable.h"

struct Player : public Savable, public Serializable
{
    String name;
    uint16 rank;

    Player(String playerName) : Savable("account")
    {
        name = playerName;
    }

    virtual void serialize(Packet* packet)
    {
        packet->addStr(name);
        packet->addU16(rank);
    }

    virtual void unserialize(Packet* packet)
    {
        packet->getStr(name);
        packet->getU16(rank);
    }

    virtual void save()
    {
        save(name + ".brawler");
    }

    virtual void save(String fileName)
    {
        Savable::save(fileName + ".brawler");
    }

    virtual void load()
    {
        load(name + ".brawler");
    }

    virtual void load(String fileName)
    {
        Savable::load(fileName + ".brawler");
    }
};

#endif // PLAYER_H
