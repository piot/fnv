/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved.
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef fnv_hash_h
#define fnv_hash_h

#include <stdint.h>
#include <stddef.h>

typedef uint32_t FnvHash;

FnvHash fnvHashString(const char* str);
FnvHash fnvHashOctets(const uint8_t* str, size_t length);

const char* fnvHashToString(const FnvHash hash, char* tempBuf, size_t maxLength);

#endif
