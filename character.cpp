#include "characters.h"

Character::Character(String n)
	: name(n)
{
    Characters::getInstance().registerCharacter(this);
}

const String& Character::getName(void) const
{
    return name;
}

void Character::serialize(Packet* packet) const
{
    packet->addStr(name);
}

void Character::unserialize(Packet* packet)
{
    packet->getStr(name);
}
