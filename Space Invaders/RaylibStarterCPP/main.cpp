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

#include "TitleScreen.h"

#include "Game.h"
#include "Player.h"
#include "Enemies.h"
#include "Helper.h"     //helper class, contains the screen dimentions for use elsewhere

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;



    InitWindow(screenWidth, screenHeight = 450, "Space Invaders");
    SetTargetFPS(30);




    //the title screen runs, and when it ends due to buttonpress, it initilises the main game class
    TitleScreen title = TitleScreen(screenWidth, screenHeight);                                   //remember to uncomment
    //Game runGame = Game(screenWidth, screenHeight);//this is here due to bug testing reasons

    // De-Initialization 
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}