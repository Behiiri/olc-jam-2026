/* ========================================================================
   $File: base.hpp$
   $Date: 2026-09-26$
   $Revision: 1$
   $Author: Behiri$
   $Notice: (C) Copyright 2026 by Behiri! All Rights Reserved.$
   ======================================================================== */

#pragma once

#include <cstdint>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;
typedef float    f32;
typedef double   f64;

typedef olc::PixelGameEngine Engine;

struct Vector2 {
    f32 x, y;
    
};

struct Vector2i {
    s32 x, y;
};
