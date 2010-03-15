#ifndef WRAPPERS_H
#define WRAPPERS_H

#include "Serializable.h"
#include "Packet.h"

namespace Sentient
{
    struct TypeWrapper : public Serializable {};

    struct S32 : public TypeWrapper
    {
	sint32 value;
	S32() {}
	S32(sint32 v) : value(v) {}
	virtual void serialize(Packet* packet) const
	{
	    packet->addS32(value);
	}
	virtual void unserialize(Packet* packet)
	{
	    packet->getS32(value);
	}
    };

    struct U32 : public TypeWrapper
    {
	uint32 value;
	U32() {}
	U32(uint32 v) : value(v) {}
	virtual void serialize(Packet* packet) const
	{
	    packet->addU32(value);
	}
	virtual void unserialize(Packet* packet)
	{
	    packet->getU32(value);
	}
    };

    struct SString : public TypeWrapper
    {
	String value;
	SString() {}
	SString(String v) : value(v) {}
	virtual void serialize(Packet* packet) const
	{
	    packet->addStr(value);
	}
	virtual void unserialize(Packet* packet)
	{
	    packet->getStr(value);
	}
    };

    struct CompareSString
    {
	bool operator() (const SString& lhs, const SString& rhs)
	{
	    return lhs.value.compare(rhs.value) < 0;
	}
    };
}

#endif // WRAPPERS_H
