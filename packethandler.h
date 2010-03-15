#ifndef PACKETHANDLER_H
#define PACKETHANDLER_H

#include "Packet.h"

#define SUCCESS 0
#define FAILURE 1

uint8 savePacket(String location, Packet* packet)
{
    FILE* file = fopen(location.c_str(), "w");
    if (file == NULL) return FAILURE;
    uint32 len = 0;
    uint8* data = packet->data(len);
    fwrite(data, 1, len, file);
    fclose(file);
    return SUCCESS;
}

Packet* loadPacket(String location)
{
    FILE* file = fopen(location.c_str(), "r");
    if (file == NULL) return 0;
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    uint8 buffer[size];
    fread(buffer, 1, size, file);
    fclose(file);
    return new Packet(buffer, size);;
}

void freePacket(Packet* packet)
{
    if (packet == 0) return;
    delete packet;
    packet = 0;
}

#endif // PACKETHANDLER_H
