#ifndef PACKETHANDLER_H
#define PACKETHANDLER_H

#include "Packet.h"

#define SUCCESS 0
#define FAILURE 1

using namespace Sentient;

uint8 savePacket(String location, Packet* packet);
Packet* loadPacket(String location);
void freePacket(Packet* packet);

#endif // PACKETHANDLER_H
