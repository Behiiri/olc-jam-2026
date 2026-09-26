/* ========================================================================
   $File: main.cpp$
   $Date: 2026-09-25$
   $Revision: 1$
   $Author: Behiri$
   $Notice: (C) Copyright 2026 by Behiri! All Rights Reserved.$
   ======================================================================== */

#include "arena.hpp"
#include "game.hpp"
#include "config.hpp"

struct Application : public olc::PixelGameEngine {
    Application() {
        sAppName = "OLC Game Jam 2026";
    }

    bool OnUserCreate() override {
        arena = new Arena();
        arena->create(1024 * 1024 * 2);

        game = arena->alloc<Game>();
        game->create(arena, this);
        
        return true;
    }

    bool OnUserUpdate(float elapsed_time) override {
        draw.Clear(olc::Colour::VERY_DARK_BLUE);

        if(keyboard.GetKey(olc::Key::Q).bPressed) {
            return false;
        }


        game->tick();
        game->render();
            
        return true;
    }

private:
    Arena *arena;
    Game *game;
};

int main() {
    Application app;

    if(app.Construct(
            { SCREEN_WIDTH, SCREEN_HEIGHT },
            { SCREEN_SCALE_X, SCREEN_SCALE_Y })
    ) {
        app.Start();
    }

    return 0;
}
