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

#ifndef SENTIENT_MUTEX_H
#define SENTIENT_MUTEX_H

#include "Platform.h"

#ifndef PLATFORM_WINDOWS
#include <pthread.h>
#else
#include <windows.h>
#endif

namespace Sentient
{
    /// Defines a cross-platform mutex.
    /// @class Mutex
    /// @note Every class in theta should be thread safe, so use a mutex please :)
    class Mutex
    {
    public:
        Mutex(void);
        ~Mutex(void);
        /// Locks the mutex instance.
        virtual void lock(void);
        /// Unlocks the mutex instance.
        /// @note undefined behavior if the mutex isn't locked
        virtual void unlock(void);
    protected:
#ifndef PLATFORM_WINDOWS
        /// Pthread mutex used under posix compliant systems
        pthread_mutex_t m_mutex;
#else
        /// Mutex used under windows systems
        CRITICAL_SECTION m_mutex;
#endif
    private:
    };
}

#endif // SENTIENT_MUTEX_H
