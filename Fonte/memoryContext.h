#pragma once

#include <stdlib.h>
#include "types.h"

void initMemoryContext();
void* uffsloc(size_t size);
void uffsFree(MemoryContextType type);
void uffsFreeRecursive(MemoryContext *context);
void* uffsRealloc(void *ptr, size_t newSize);