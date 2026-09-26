/* ========================================================================
   $File: painter.hpp$
   $Date: 2026-09-26$
   $Revision: 1$
   $Author: Behiri$
   $Notice: (C) Copyright 2026 by Behiri! All Rights Reserved.$
   ======================================================================== */

#pragma once 

struct Painter {
    bool create(Engine *engine);

    void draw_rect(Vector2 pos, Vector2 size, int color);

private:
    olc::Draw *draw;
};
