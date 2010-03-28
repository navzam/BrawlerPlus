#ifndef PLAYER_H
#define PLAYER_H

#include "string"
#include "Savable.h"
#include "Map.h"
#include "Wrappers.h"

struct Player : public Savable, public Serializable
{
    typedef SerializableMap<SString, U32, CompareSString> MapType;
    String name;
    MapType wins;
    MapType losses;
    uint16 groupWins;
    uint16 groupLosses;
    uint16 KOs;

    Player(String playerName) : Savable("account")
    {
        name = playerName;
        groupWins = 0;
        groupLosses = 0;
        KOs = 0;
    }

    virtual void serialize(Packet* packet) const
    {
	wins.serialize(packet);
	losses.serialize(packet);
        packet->addStr(name);
        packet->addU16(groupWins);
        packet->addU16(groupLosses);
	packet->addU16(KOs);
    }

    virtual void unserialize(Packet* packet)
    {
	wins.unserialize(packet);
	losses.unserialize(packet);
        packet->getStr(name);
        packet->getU16(groupWins);
        packet->getU16(groupLosses);
        packet->getU16(KOs);
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

    uint32 getGamesPlayed()
    {
	return getGamesWon() + getGamesLost();
    }

    uint32 getGamesLost()
    {
	uint32 ret = 0;
	for (MapType::const_iterator it = losses.begin(); it != losses.end(); ++it)
	{
	    ret += (*it).second.value;
	}
	return ret;
    }

    uint32 getGamesWon()
    {
	uint32 ret = 0;
	for (MapType::const_iterator it = wins.begin(); it != wins.end(); ++it)
	{
	    ret += (*it).second.value;
	}
	return ret;
    }
};

#endif // PLAYER_H
