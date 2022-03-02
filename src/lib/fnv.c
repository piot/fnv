/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <fnv/fnv.h>
#include <tiny-libc/tiny_libc.h>

static const FnvHash FNV_PRIME = 16777619u;
static const FnvHash OFFSET_BASIS = 2166136261u;

// Similar to FNV-1a https://en.wikipedia.org/wiki/Fowler-Noll-Vo_hash_function

FnvHash fnvHashOctets(const uint8_t* str, size_t length)
{
    FnvHash hash = OFFSET_BASIS;
    for (size_t i = 0; i < length; ++i) {
        hash ^= (uint8_t) *str++;
        hash *= FNV_PRIME;
    }
    return hash;
}


FnvHash fnvHashString(const char* str)
{
	const size_t length = tc_strlen(str) + 1;
    return fnvHashOctets((const uint8_t*) str, length);
}


const char* fnvHashToString(const FnvHash hash, char* tempBuf, size_t maxLength)
{
    int result = tc_snprintf(tempBuf, maxLength, "%04X", hash);
    if (result < 0) {
        return "hasherror";
    }

    return tempBuf;
}
