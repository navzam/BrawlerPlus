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

#ifndef SENTIENT_PACKET_H
#define SENTIENT_PACKET_H

#include "Types.h"
#include "Mutex.h"

#define STRING_HEADER_TYPE uint32

namespace Sentient
{
	typedef List<uint8> ByteList;

    class Packet : public Mutex
    {
    public:
        Packet(void);
        Packet(const uint8* data, const uint32 size);
        Packet(const String& event);
        virtual ~Packet(void);

        virtual bool check(uint32 numBytes = 0);
        virtual bool checkEqual(uint32 numBytes);

        virtual void addU8(uint8 value);
        virtual void addU16(uint16 value);
        virtual void addU32(uint32 value);

        virtual void addS8(sint8 value);
        virtual void addS16(sint16 value);
        virtual void addS32(sint32 value);

        virtual void addR32(real32 value);

        virtual void addStr(String value);
        virtual void addData(uint8* data, const uint32 len);

        virtual void prependU8(uint8 value);
        virtual void prependU16(uint16 value);
        virtual void prependU32(uint32 value);
		virtual void prependStr(String value);

		virtual void getU8(uint8& value);
        virtual void getU16(uint16& value);
        virtual void getU32(uint32& value);

        virtual void getS8(sint8& value);
        virtual void getS16(sint16& value);
        virtual void getS32(sint32& value);

        virtual void getR32(real32& value);

        virtual void getStr(String& value);
        virtual void getData(uint8*& data, uint32& len);

        virtual uint8* data(uint32& len);

        void event(String event);
        String event(void);

        enum
        {
        	Read,
        	Write
        };
    protected:
        ByteList m_data;
    private:
		String m_event;
    };
}

#endif // SENTIENT_PACKET_H
