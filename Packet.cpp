/*
 * Copyright (c) 2009 Braden McDorman
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "Packet.h"
//#include "Log.h"
#include <cstring>
#include <iostream>

using namespace Sentient;

Packet::Packet(void)
{
    lock();
    m_event = "";
    unlock();
}

Packet::Packet(const uint8* data, const uint32 size)
{
	// Log::ref().notice(reinterpret_cast<const char*>(data));
	lock();
	// Log::ref().notice("Packing data...");
    for(uint32 it = 0; it < size; ++it)
    {
		//Log::ref().bits(data[it]);
    	m_data.push_back(data[it]);
    }
    unlock();
    String eventName;
    //Log::ref().notice("Getting event string...");
    getStr(eventName);
    //Log::ref().notice("Got " + eventName);
    // Log::ref().notice(eventName);
    this->event(eventName);
}

Packet::Packet(const String& event)
{
    this->event(event);
}

Packet::~Packet(void)
{
}

bool Packet::check(uint32 numBytes)
{
	bool available = false;
	lock();
	available = (m_data.size() >= numBytes);
	unlock();
	return available;
}

bool Packet::checkEqual(uint32 numBytes)
{
	bool available = false;
	lock();
	available = (m_data.size() == numBytes);
	unlock();
	return available;
}


void Packet::addU8(uint8 value)
{
    lock();
    m_data.push_back(value);
    //Log::ref().bits(value);
    unlock();
}

void Packet::addU16(uint16 value)
{
    addU8((value & 0xFF00) >> 8);
    addU8((value & 0x00FF) >> 0);
}

void Packet::addU32(uint32 value)
{
    addU8((value & 0xFF000000) >> 24);
    addU8((value & 0x00FF0000) >> 16);
    addU8((value & 0x0000FF00) >> 8);
    addU8((value & 0x000000FF) >> 0);
}

void Packet::addS8(sint8 value)
{
    addU8(static_cast<uint8>(value));
}

void Packet::addS16(sint16 value)
{
    addU8((value & 0xFF00) >> 8);
    addU8((value & 0x00FF) >> 0);
}

void Packet::addS32(sint32 value)
{
    addU8((value & 0xFF000000) >> 24);
    addU8((value & 0x00FF0000) >> 16);
    addU8((value & 0x0000FF00) >> 8);
    addU8((value & 0x000000FF) >> 0);
}

void Packet::addR32(real32 value)
{
    uint32 uval = static_cast<uint32>(value);
    addU8((uval & 0xFF000000) >> 24);
    addU8((uval & 0x00FF0000) >> 16);
    addU8((uval & 0x0000FF00) >> 8);
    addU8((uval & 0x000000FF) >> 0);
}

void Packet::addStr(String value)
{
	addU32(value.size());
    for (uint32 i = 0; i < value.size(); ++i)
    {
        addU8(static_cast<uint8>(value[i]));
    }
}

void Packet::addData(uint8* data, const uint32 len)
{
	addU32(len);
    for (uint32 i = 0; i < len; ++i)
    {
        addU8(data[i]);
    }
}

void Packet::prependU8(uint8 value)
{
	lock();
    m_data.push_front(value);
    unlock();
}

void Packet::prependU16(uint16 value)
{
	prependU8((value & 0x00FF) >> 0);
	prependU8((value & 0xFF00) >> 8);
}

void Packet::prependU32(uint32 value)
{
	prependU8((value & 0x000000FF) >> 0);
    prependU8((value & 0x0000FF00) >> 8);
    prependU8((value & 0x00FF0000) >> 16);
    prependU8((value & 0xFF000000) >> 24);
}

void Packet::prependStr(String value)
{
	for (uint32 i = value.size(); i > 0; --i)
    {
        prependU8(static_cast<uint8>(value[i - 1]));
    }
	prependU32(value.size());
}

void Packet::getU8(uint8& value)
{
    lock();
    value = m_data.front();
    // Log::ref().bits(value);
    m_data.pop_front();
    unlock();
}

void Packet::getU16(uint16& value)
{
    uint8 byte = 0;
    getU8(byte);
    value <<= 8;
    value |= byte;
    getU8(byte);
    value <<= 8;
    value |= byte;
}

void Packet::getU32(uint32& value)
{
    uint8 byte = 0;
    getU8(byte);
    value <<= 8;
    value |= byte;
    getU8(byte);
    value <<= 8;
    value |= byte;
    getU8(byte);
    value <<= 8;
    value |= byte;
    getU8(byte);
    value <<= 8;
    value |= byte;
}

void Packet::getS8(sint8& value)
{
    uint8 byte = 0;
    getU8(byte);
    value = static_cast<sint8>(byte);
}

void Packet::getS16(sint16& value)
{
    sint8 byte = 0;
    getS8(byte);
    value <<= 8;
    value |= byte;
    getS8(byte);
    value <<= 8;
    value |= byte;
}

void Packet::getS32(sint32& value)
{
    sint8 byte = 0;
    getS8(byte);
    value <<= 8;
    value |= byte;
    getS8(byte);
    value <<= 8;
    value |= byte;
    getS8(byte);
    value <<= 8;
    value |= byte;
    getS8(byte);
    value <<= 8;
    value |= byte;
}

void Packet::getR32(real32& value)
{
    uint32 bytes = 0;
    getU32(bytes);
    value = static_cast<real32>(bytes);
}

void Packet::getStr(String& value)
{
    String tmp;
    uint8 val = 0;
    uint32 length = 0;
    getU32(length);
    for(uint32 i = 0; i < length; ++i)
    {
        getU8(val);
        tmp.append(1, val);
    }
    value = tmp;
}

void Packet::getData(uint8*& data, uint32& len)
{
	getU32(len);
	data = new uint8[len];
    for (uint32 i = 0; i < len; ++i)
    {
        getU8(data[i]);
    }
}

uint8* Packet::data(uint32& len)
{
	if(event().empty())
	{
		// Log::ref().warning("Data accessed without proper event information. Returning 0.");
		return 0;
	}
    uint8* data = 0;
    lock();
    ByteList old = m_data;
    unlock();
    prependStr(m_event);
    lock();
    len = m_data.size();
    data = new uint8[len + 1];
    uint32 i = 0;
    for (ByteList::iterator it = m_data.begin(); it != m_data.end(); ++it)
    {
		// Log::ref().bits(*it);
        data[i] = (*it);
        ++i;
    }
    unlock();
    m_data = old;
    // Log::ref().notice("Returning data: " + String(reinterpret_cast<char*>(data)));
    return data;
}

void Packet::event(String event)
{
    lock();
    m_event = event;
    unlock();
}

String Packet::event(void)
{
    String event;
    lock();
    event = m_event;
    unlock();
    return event;
}

