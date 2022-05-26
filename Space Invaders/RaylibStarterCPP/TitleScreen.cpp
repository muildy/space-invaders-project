#include <cstdlib>
#include <iostream>
#include <stdlib.h>

#include "TitleScreen.h"
#include "Game.h"

typedef unsigned char  uchar;

struct Star {
    int x;
    int y;

    Color colour;
};


TitleScreen::TitleScreen(int screenWidth, int screenHeight)
{
    {

        //button items
        bool mCheckStart = false;
        bool mCheckExit = false;
        Rectangle startbutton = Rectangle{ 40.0f, 240.0f, 150.0f, 30.0f };//{x,y,width,height}
        Rectangle exitbutton = Rectangle{ 40.0f, 280.0f, 150.0f, 30.0f };

        //setup to draw all the stars on title screen
        const int starsAmount = 800;
        Star* stars[starsAmount];
        for (int i = 0; i < starsAmount; i++) {
            stars[i] = new Star{ (rand() % screenWidth),(rand() % screenHeight) };//Star{x pos, y pos}, colour is set later for blinky flashy lights
        }

        //main game loop, but for title screen
        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            // Update
            //----------------------------------------------------------------------------------
            // TODO: Update your variables here
            //----------------------------------------------------------------------------------

            for (int i = 0; i < starsAmount; i++) {
                stars[i]->colour.a = (rand() + 100) % 255;
                stars[i]->colour.r = (rand() + 100) % 255;
                stars[i]->colour.g = (rand() + 100) % 200;
                stars[i]->colour.b = (rand() + 100) % 255;
            }

            //checks for if the mouse is hovering over the buttons and if it clicks while this happens
            //start button check
            if (CheckCollisionPointRec(GetMousePosition(), startbutton)) {
                mCheckStart = true;
                if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                    break;
            }
            else
                mCheckStart = false;
            //the check for exit button
            if (CheckCollisionPointRec(GetMousePosition(), exitbutton)) {
                mCheckExit = true;
                if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                    return;
                }
            }
            else
                mCheckExit = false;
            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();

            ClearBackground(BLACK);


            //draws all the "stars" and the main title text
            for (int i = 0; i < starsAmount; i++) {
                DrawCircle(stars[i]->x, stars[i]->y, 3, stars[i]->colour);
                DrawText("SPACE INVADERS", 40 + (rand() % 10), 165 + (rand() % 10), 70, stars[i]->colour);
                DrawText("by Adam 2022", (screenWidth - 84) + (rand() % 2), (screenHeight - 15) + (rand() % 3), 7, stars[i]->colour);
            }
            //menu buttons 
            DrawRectangleRec(startbutton, (mCheckStart) ? LIGHTGRAY : DARKGRAY);
            DrawRectangleRec(exitbutton, (mCheckExit) ? LIGHTGRAY : DARKGRAY);
            DrawText("START", startbutton.x + 5 + (rand() % 5), startbutton.y + 5 + (rand() % 2), 20, WHITE);
            DrawText("EXIT", exitbutton.x + 5 + (rand() % 5), exitbutton.y + 5 + (rand() % 2), 20, WHITE);


            EndDrawing();
            //---------------------------------------------------------------------------------- 
        }
        //deleting all the star structs
        for (int i = 0; i < starsAmount; i++) {
            stars[i] = nullptr;
            delete(stars[i]);
        }
    }//this makes everything except for game fall out of scope, clearing it. it doesnt really do much for performance, but i like the idea of all the stuff being cleaned
    //after the loop ends due to the breaks, it is assumed that game will then run due to the logic within
    Game game = Game(screenWidth, screenHeight);
}

TitleScreen::~TitleScreen()
{
    std::cout << "titlescreen cleared" << std::endl;
}
