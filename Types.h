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

#ifndef SENTIENT_TYPES_H
#define SENTIENT_TYPES_H

#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include <fstream>

namespace Sentient
{
	// Base types
    typedef unsigned char uint8;
    typedef unsigned short uint16;
    typedef unsigned int uint32;
    typedef unsigned long long uint64;

    typedef char sint8;
    typedef short sint16;
    typedef int sint32;
    typedef long long sint64;

    typedef float real32;
    typedef double real64;

	// STL
    typedef std::string String;
    typedef std::fstream FileStream;
    typedef std::stringstream StringStream;
    template <typename T0> class Vector : public std::vector<T0> {};
    template <typename T0> class List : public std::list<T0> {};
    template <typename T0, typename T1> class Map : public std::map<T0, T1> {};
    template <typename T0, typename T1> class Pair : public std::pair<T0, T1> {};
    typedef List<String> StringList;

    // Handles
    typedef std::pair<uint32, String> IdentifiedString;
    typedef List<IdentifiedString> IdentifiedStringList;
}

#endif // SENTIENT_TYPES_H
