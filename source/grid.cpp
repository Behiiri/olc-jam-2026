/* ========================================================================
   $File: grid.cpp$
   $Date: 2026-09-26$
   $Revision: 1$
   $Author: Behiri$
   $Notice: (C) Copyright 2026 by Behiri! All Rights Reserved.$
   ======================================================================== */

#include "grid.hpp"
#include "painter.hpp"
#include "config.hpp"

bool Grid::create(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;

    cell_width   = 16.0f;
    cell_height  = 16.0f;
    cell_spacing = 1.0f;

    position.x = (SCREEN_WIDTH  - (cell_width + cell_spacing)  * columns) * 0.5f;
    //position.y = (SCREEN_HEIGHT - (cell_height + cell_spacing) * rows)    * 0.5f;
    position.y = SCREEN_HEIGHT * 0.05f;
    
    return true;   
}

void Grid::render(Painter *painter) {
    f32 cursor_x = position.x;
    f32 cursor_y = position.y;
    
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j) {
            // int x = (int)((cell_width + cell_spacing) * j);
            // int y = (int)((cell_height + cell_spacing) * h);
            painter->draw_rect({cursor_x, cursor_y}, {cell_width, cell_height}, 0xff0000ff);
            cursor_x += cell_width + cell_spacing;
        }

        cursor_x = position.x;
        cursor_y += cell_height + cell_spacing;
    }
}
