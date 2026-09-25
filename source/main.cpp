/* ========================================================================
   $File: main.cpp$
   $Date: 2026-09-25$
   $Revision: 1$
   $Author: Behiri$
   $Notice: (C) Copyright 2026 by Behiri! All Rights Reserved.$
   ======================================================================== */

#include "olcPixelGameEngine3.h"

struct Application : public olc::PixelGameEngine {
    Application() {
        sAppName = "OLC Game Jam 2026";
    }

    bool OnUserCreate() override {
        return true;
    }

    bool OnUserUpdate(float elapsed_time) override {
        draw.Clear(olc::Colour::VERY_DARK_BLUE);

        if(keyboard.GetKey(olc::Key::Q).bPressed) {
            return false;
        }

        return true;
    }
};

int main() {
    Application app;

    if (app.Construct({ 256, 240 }, { 4, 4 })) {
        app.Start();
    }

    return 0;
}
