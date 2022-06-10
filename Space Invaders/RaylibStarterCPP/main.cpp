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

#include "TitleScreen.h"
#include "Game.h"
#include "DeathScreen.h"

typedef enum GameState { TITLE = 0, GAME, ENDING } GameState;

void main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;
    
    //



    InitWindow(screenWidth, screenHeight = 450, "Space Invaders");
    SetTargetFPS(30);
    DeathScreen ded = DeathScreen(5);
    //TitleScreen titlescreen = TitleScreen();
    //Game runGame = Game();
    //while (true) {
    //    switch (currentState) {
    //    case TITLE:
    //        TitleScreen titlescreen;titlescreen = TitleScreen();
    //        break;
    //    case GAME:
    //        break;
    //    default:
    //        break;
    //    }
    //}
    
    // De-Initialization 
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
}
