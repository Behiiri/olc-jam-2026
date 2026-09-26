/* ========================================================================
   $File: game.hpp$
   $Date: 2026-09-26$
   $Revision: 1$
   $Author: Behiri$
   $Notice: (C) Copyright 2026 by Behiri! All Rights Reserved.$
   ======================================================================== */

#pragma once

struct Arena;
struct Grid;
struct Painter;

struct Game {
    bool create(Arena *arena, Engine *engine);
    void reset();
    
    void tick();
    void handle_input();
    void render();

private:
    Engine  *engine;
    Arena   *arena;
    Grid    *grid;
    Painter *painter;
};
