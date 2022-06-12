#include "DeathScreen.h"

DeathScreen::DeathScreen(){}

DeathScreen::~DeathScreen(){}

DeathScreen::DeathScreen(int score)
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    int offset = 5;
    //button item
    bool mCheckStart = false;

    Rectangle startbutton = Rectangle{ 40.0f, 240.0f, 150.0f, 30.0f };//{x,y,width,height}

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        //checks for if the mouse is hovering over the buttons and if it clicks while this happens
        //start button check
        if (CheckCollisionPointRec(GetMousePosition(), startbutton)) {
            mCheckStart = true;
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                break;
        }
        else
            mCheckStart = false;

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        DrawText(TextFormat("Final Score: %04i", score), 40 , 130, 70, WHITE);//{char*, X, Y, fontsize, colour
        //menu buttons 
        DrawRectangleRec(startbutton, (mCheckStart) ? LIGHTGRAY : DARKGRAY);
        DrawText("Try again?", startbutton.x + offset, startbutton.y + offset, 20, WHITE);

        EndDrawing();
        //---------------------------------------------------------------------------------- 
    }
    Game game = Game();//this is the way it is because i forgot about getters and setters existing
}


