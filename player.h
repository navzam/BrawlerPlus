#ifndef PLAYER_H
#define PLAYER_H

#include "string"
#include "Savable.h"
#include "Map.h"
#include "Wrappers.h"

struct Player : public Savable, public Serializable
{
    String name;
    SerializableMap<SString, U32, CompareSString> wins;
    SerializableMap<SString, U32, CompareSString> losses;
    uint16 groupWins;
    uint16 groupLosses;
    uint16 KOs;
    uint16 games;

    Player(String playerName) : Savable("account")
    {
        name = playerName;
        groupWins = 0;
        groupLosses = 0;
        KOs = 0;
	games = 0;
    }

    virtual void serialize(Packet* packet) const
    {
	wins.serialize(packet);
	losses.serialize(packet);
        packet->addStr(name);
        packet->addU16(groupWins);
        packet->addU16(groupLosses);
	packet->addU16(KOs);
	packet->addU16(games);
    }

    virtual void unserialize(Packet* packet)
    {
	wins.unserialize(packet);
	losses.unserialize(packet);
        packet->getStr(name);
        packet->getU16(groupWins);
        packet->getU16(groupLosses);
        packet->getU16(KOs);
	packet->getU16(games);
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
