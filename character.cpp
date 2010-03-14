#include "character.h"
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
