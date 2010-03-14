#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "Packet.h"

using namespace Sentient;

struct Serializable
{
    virtual void serialize(Packet* packet) const = 0;
    virtual void unserialize(Packet* packet) = 0;
};

#endif
