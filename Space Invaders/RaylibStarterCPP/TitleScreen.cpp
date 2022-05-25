#include <cstdlib>
#include <iostream>

#include "TitleScreen.h"
#include "gameObject.h"

struct Star {
    int x;
    int y;

    Color colour;
};


TitleScreen::TitleScreen(int screenWidth, int screenHeight)
{
    const int starsAmount = 100;
    Star* stars[starsAmount];

    for (int i = 0; i < starsAmount; i++) {
        stars[i] = new Star;
        stars[i]->x = rand() % screenWidth;
        stars[i]->y = rand() % screenHeight;
        stars[i]->colour.a = rand() % 255;
        stars[i]->colour.r = rand() % 255;
        stars[i]->colour.g = rand() % 255;
        stars[i]->colour.b = rand() % 255;
    }

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {


        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        for (int i = 0; i < starsAmount; i++) {
            DrawCircle(stars[i]->x, stars[i]->y, 2, stars[i]->colour);
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
        //---------------------------------------------------------------------------------- 
    }
}

TitleScreen::~TitleScreen()
{
    
}
