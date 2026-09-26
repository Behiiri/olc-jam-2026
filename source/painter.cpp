/* ========================================================================
   $File: painter.cpp$
   $Date: 2026-09-26$
   $Revision: 1$
   $Author: Behiri$
   $Notice: (C) Copyright 2026 by Behiri! All Rights Reserved.$
   ======================================================================== */

#include "painter.hpp" 

bool Painter::create(Engine *engine) {
    this->draw = &engine->GetDraw();

    return true;
}

void Painter::draw_rect(Vector2 pos, Vector2 size, int color) {
    draw->FilledRect({ pos.x, pos.y }, { size.x, size.y }, olc::Pixel(color));
}
