#ifndef SAVABLE_H
#define SAVABLE_H

#include "Serializable.h"
#include "Types.h"
#include "Packet.h"
#include "packethandler.h"

struct Savable : public Serializable
{
private:
    String eventName;
protected:
    String getEventName()
    {
        return eventName;
    }
    void setEventName(String& name)
    {
        eventName = name;
    }
public:
    Savable() : eventName("") {}
    Savable(String name) : eventName(name) {}

    uint8 save(String location)
    {
        Packet toSave(eventName);

        serialize(&toSave);

        return savePacket(location, &toSave); // Invoke low-level saver, returns success or failure
    }

    uint8 load(String location)
    {
        Packet* loaded = loadPacket(location);
        if (loaded == 0) return FAILURE;
        if (loaded->event().compare(eventName) != 0) return FAILURE;

        // You MUST load in the same order as you saved
        unserialize(loaded);

        // Free allotted packet
        freePacket(loaded);
        return SUCCESS;
    }
};

#endif // SAVABLE_H
