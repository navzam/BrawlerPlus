#ifndef CHARACTER_H
#define CHARACTER_H

#include "Types.h"
#include "Serializable.h"

using namespace Sentient;

class Character : public Serializable
{
    String name;
public:
    Character(String n);
    const String& getName(void) const;
    void serialize(Packet* packet) const;
    void unserialize(Packet* packet);
};

#endif // CHARACTER_H
