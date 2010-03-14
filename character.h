#ifndef CHARACTER_H
#define CHARACTER_H

#include "Types.h"

using namespace Sentient;

class Character
{
    String name;
public:
    Character(String n);
    const String& getName(void) const;
};

#endif // CHARACTER_H
