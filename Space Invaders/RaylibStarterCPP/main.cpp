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
#include <iostream>

#include "raylib.h"
#include "raymath.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

#include "gameObject.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Space Invaders");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_A)|| IsKeyDown(KEY_LEFT)) {
            std::cout << "A" << std::endl;
        };
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
            std::cout << "D" << std::endl;
        };
        if (IsKeyPressed(KEY_SPACE)) {
            std::cout << "SPACE" << std::endl;
        };


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE); 

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