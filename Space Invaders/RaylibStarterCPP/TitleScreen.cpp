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
    const int starsAmount = 800;
    Star* stars[starsAmount];

    //for (int i = 0; i < starsAmount; i++) {
    //    stars[i] = new Star;
    //    stars[i]->x = rand() % screenWidth;
    //    stars[i]->y = rand() % screenHeight;
    //    stars[i]->colour.a = (rand() + 100) % 255;
    //    stars[i]->colour.r = (rand() + 100) % 255;
    //    stars[i]->colour.g = (rand() + 100) % 200;
    //    stars[i]->colour.b = (rand() + 100) % 255;
    //}
    int counter = 0;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        counter++;

        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        for (int i = 0; i < starsAmount; i++) {
            stars[i] = new Star;
            stars[i]->x = i;//rand() % screenWidth;
            stars[i]->y = sin(i) * 100;//rand() % screenHeight;
            stars[i]->colour.a = (rand() + 100) % 255;
            stars[i]->colour.r = (rand() + 100) % 255;
            stars[i]->colour.g = (rand() + 100) % 200;
            stars[i]->colour.b = (rand() + 100) % 255;
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);



        for (int i = 0; i < starsAmount; i++) {
            DrawCircle(stars[i]->x, stars[i]->y, 3, stars[i]->colour);
            stars[i] = nullptr;
            delete(stars[i]);
        }


        EndDrawing();
        //---------------------------------------------------------------------------------- 
    }
    //for (int i = 0; i < starsAmount; i++) {
    //    stars[i] = nullptr;
    //    delete(stars[i]);
    //}
}

TitleScreen::~TitleScreen()
{
    
}
