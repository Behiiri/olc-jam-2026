/* ========================================================================
   $File: arena.hpp$
   $Date: 2025-01-13&
   $Revision: 6$
   $Creator: Behiri $
   $Notice: (C) Copyright 2025 by Behiri! All Rights Reserved. $
   ======================================================================== */

# pragma once

#include <new>
#include <stddef.h>

struct Arena {
    void create(size_t size);
    void clear();
    void destroy();

    template <typename T>
    T *alloc() {
        void *memory = alloc_aligned(sizeof(T), alignof(T));
        if (!memory) {
            return NULL;
        }
        return new (memory) T();
    }

    void *alloc_bytes(size_t size);
    void *alloc_aligned(size_t size, size_t align);

    void *get_base_address() { return arena; }

    Arena *create_sub_arena(size_t size);

private:
    void   *arena     = NULL;
    void   *current   = NULL;
    void   *end       = NULL;
    size_t  size      = 0;
    size_t  alignment = 0;
};
