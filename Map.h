#ifndef MAP_H
#define MAP_H

#include <map>
#include "Packet.h"

using namespace std;

namespace Sentient
{
    template <class K, class T, class C>
	    struct SerializableMap : public map<K, T, C>, public Serializable
    {
    private:
	typedef map<K, T, C> MapType;
    public:
	virtual void serialize(Packet* packet) const
	{
	    packet->addU16(MapType::size());
	    for (typename MapType::const_iterator it = MapType::begin(); it != MapType::end(); ++it)
	    {
		(*it).first.serialize(packet);
		(*it).second.serialize(packet);
	    }
	}
	virtual void unserialize(Packet* packet)
	{
	    uint16 size = 0;
	    packet->getU16(size);
	    for (uint16 i = 0; i < size; ++i)
	    {
		K k_t;
		T t_t;
		k_t.unserialize(packet);
		t_t.unserialize(packet);
		MapType::insert(pair<K, T>(k_t, t_t));
	    }
	}
    };
}

#endif // MAP_H
