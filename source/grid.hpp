/* ========================================================================
   $File: grid.hpp$
   $Date: 2026-09-26$
   $Revision: 1$
   $Author: Behiri$
   $Notice: (C) Copyright 2026 by Behiri! All Rights Reserved.$
   ======================================================================== */

#pragma once

struct Painter;

struct Grid {
    bool create(int rows, int columns);
    void render(Painter *painter);

private:
    Vector2 position;
    
    int rows;
    int columns;

    float cell_width;
    float cell_height;
    float cell_spacing;
};
