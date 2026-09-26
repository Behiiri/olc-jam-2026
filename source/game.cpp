/* ========================================================================
   $File: game.cpp$
   $Date: 2026-09-26$
   $Revision: 1$
   $Author: Behiri$
   $Notice: (C) Copyright 2026 by Behiri! All Rights Reserved.$
   ======================================================================== */

#include "game.hpp"
#include "arena.hpp"
#include "grid.hpp"
#include "painter.hpp"

bool Game::create(Arena *arena, Engine *engine) {
    this->arena = arena;

    grid = arena->alloc<Grid>();
    grid->create(8, 8);

    painter = arena->alloc<Painter>();
    painter->create(engine);

    return true;
}

void Game::reset() {
}

void Game::tick() {
}

void Game::handle_input() {
    
}

void Game::render() {
    grid->render(painter);
}
