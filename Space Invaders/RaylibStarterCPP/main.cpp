/******************************************************************************************
|                                                                                           \ 
|   raylib [core] example - Basic window                                                    |
|                                                                                           |
|   Welcome to raylib!                                                                      |
|                                                                                           |
|   To test examples, just press F6 and execute raylib_compile_execute script               |
|   Note that compiled executable is placed in the same folder as .c file                   |
|                                                                                           |
|   You can find all basic examples on C:\raylib\raylib\examples folder or                  |
|   raylib official webpage: www.raylib.com                                                 |
|                                                                                           |
|   Enjoy using raylib. :)                                                                  |
|                                                                                           |
|   This example has been created using raylib 1.0 (www.raylib.com)                         |
|   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)  |
|                                                                                           |
|   Copyright (c) 2014 Ramon Santamaria (@raysan5)                                          |
\                                                                                           |
  ******************************************************************************************/
//https://www.youtube.com/watch?v=MkpxwsybNPo&t=75s&ab_channel=Hopson ~usefull video
#include <iostream>

#include "raylib.h"
#include "raymath.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

#include "Game.h"
#include "Player.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Space Invaders");

    SetTargetFPS(60);

    Player* player = new Player(screenWidth/2 , screenHeight-(screenHeight/8), 10);

    Player* player = new Player(screenWidth/2 , (screenHeight/8), 10);
    //--------------------------------------------------------------------------------------

    

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        
        
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------


        player->update();


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE); 

        player->draw();
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //---------------------------------------------------------------------------------- 
    }

    // De-Initialization 
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}