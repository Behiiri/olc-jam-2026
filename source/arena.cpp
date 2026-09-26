/* ========================================================================
   $File: arena.cpp$
   $Date: 2025-01-13&
   $Revision: 11$
   $Creator: Behiri $
   $Notice: (C) Copyright 2025 by Behiri! All Rights Reserved. $
   ======================================================================== */

#include "arena.hpp"

static inline uintptr_t align_forward_uintptr(uintptr_t p, size_t align) {
    return (p + (align - 1)) & ~(align - 1);
}

void Arena::create(size_t arena_size) {
    arena = malloc(arena_size);
    if (!arena) return;
    
    size = arena_size;
    current = arena;
    end = (uint8_t *)arena + size;

    alignment = alignof(std::max_align_t);
}

void Arena::clear() {
    if (arena) {
        current = arena;
        // mark_cleared(arena, size);
    }
}

void Arena::destroy() {
    if (arena) {
        free(arena);
        arena = NULL;
        current = NULL;
        end = NULL;
        size = 0;
    }
}

void *Arena::alloc_bytes(size_t alloc_size) {
    return alloc_aligned(alloc_size, alignment);
}

void *Arena::alloc_aligned(size_t alloc_size, size_t align) {
    uintptr_t cur = (uintptr_t)current;
    uintptr_t aligned = align_forward_uintptr(cur, align);
    size_t padding = aligned - cur;

    if ((uint8_t *)current + padding + alloc_size > end) {
        return NULL;
    }

    void *result = (void *)aligned;
    current = (uint8_t *)aligned + alloc_size;
    return result;
}


Arena *Arena::create_sub_arena(size_t buffer_size) {
    size_t arena_align = alignof(Arena);
    size_t arena_size = (sizeof(Arena) + arena_align - 1) & ~(arena_align - 1);
    size_t total = arena_size + buffer_size;

    uintptr_t cur = (uintptr_t)current;
    uintptr_t aligned = align_forward_uintptr(cur, arena_align);

    if ((uint8_t *)aligned + total > end) {
        return NULL;
    }

    Arena *sub = new ((void *)aligned) Arena();

    sub->arena   = (uint8_t *)aligned + arena_size;
    sub->current = sub->arena;
    sub->end     = (uint8_t *)aligned + total;
    sub->size    = buffer_size;
    sub->alignment = alignment;

    current = (uint8_t *)aligned + total;
    return sub;
}
