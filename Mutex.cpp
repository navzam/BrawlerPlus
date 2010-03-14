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

#include "Mutex.h"

using namespace Sentient;

Mutex::Mutex(void)
{
#ifndef PLATFORM_WINDOWS
    pthread_mutex_init(&m_mutex, NULL);
#else
    InitializeCriticalSection (&m_mutex);
#endif
}

Mutex::~Mutex(void)
{
#ifndef PLATFORM_WINDOWS
    pthread_mutex_destroy(&m_mutex);
#else
    DeleteCriticalSection (&m_mutex);
#endif

}

void Mutex::lock(void)
{
#ifndef PLATFORM_WINDOWS
    pthread_mutex_lock(&m_mutex);
#else
    EnterCriticalSection (&m_mutex);
#endif
}

void Mutex::unlock(void)
{
#ifndef PLATFORM_WINDOWS
    pthread_mutex_unlock(&m_mutex);
#else
    LeaveCriticalSection (&m_mutex);
#endif
}
