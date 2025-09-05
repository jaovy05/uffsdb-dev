#include "memoryContext.h"
#include "types.h" // MemoryContextType e MemoryContextRoot
#include "macros.h"
#include <stdio.h> // NULL, printf
#include <string.h> // memcpy
#include <stdlib.h> // calloc, free

MemoryContextRoot root;

void initMemoryContext() {
    root.temporary = NULL;
    root.permanent = NULL;
    // root.permanent = calloc(1, sizeof(MemoryContext)); talvez futuramente
}

void* uffslloc(size_t size) {
    size += 1;
    MemoryContext *context = root.temporary;
    while(context) {
        // confere se na lista tem algum filho com um espacinho que não foi usado antes
        if(context->used + size <= MEMORY_CONTEXT_SIZE) { 
            uffs_mem_header *ptr = (uffs_mem_header *)(context->memoryPool + context->used);
            ptr->size = size;
            context->used += sizeof(uffs_mem_header) + size;
            ptr->data[size - 1] = '\0';
            return ptr->data;
        }
        context = context->next;
    }

    // se não tem espaço em nenhum contexto, cria um novo
    MemoryContext *newContext = calloc(1, sizeof(MemoryContext));
    if(!newContext) {
        printf("Memory allocation failed for new memory context\n");
        return NULL;
    }
    newContext->type = TEMPORARY; // por enquanto é fixo
    newContext->used =  sizeof(uffs_mem_header) + size;
    newContext->next = root.temporary ? root.temporary->next : NULL;
    root.temporary = newContext;
    uffs_mem_header *ptr = (uffs_mem_header *)(newContext->memoryPool);
    ptr->size = size;
    ptr->data[size - 1] = '\0';
    return ptr->data;
}


void uffsFree(MemoryContextType type) {
    if (!root.temporary) return;
    MemoryContext *context = root.temporary;
    uffsFreeRecursive(context->next);
    memset(context, 0, sizeof(MemoryContext));
}

void uffsFreeRecursive(MemoryContext *context){
    if(context == NULL) return;
    uffsFreeRecursive(context->next);
    free(context);
    context = NULL;
}

void *uffsRealloc(void *ptr, size_t newSize) {
    if(ptr == NULL) return uffslloc(newSize);

    uffs_mem_header *header = (uffs_mem_header *)((char *)ptr - sizeof(uffs_mem_header));
    size_t oldSize = header->size - 1; // desconsidera o \0
    if(newSize <= oldSize) {
        header->size = newSize + 1;
        header->data[newSize] = '\0';
        return ptr;
    }
    void *newPtr = uffslloc(newSize);

    memcpy(newPtr, ptr, oldSize); 
    return newPtr;
}

void destroyMemoryContext() {
    if (root.temporary) {
        uffsFreeRecursive(root.temporary);
        root.temporary = NULL;
    }
    if (root.permanent) {
        uffsFreeRecursive(root.permanent);
        root.permanent = NULL;
    }
}