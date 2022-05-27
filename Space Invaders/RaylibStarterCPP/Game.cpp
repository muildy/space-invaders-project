//https://www.raylib.com/examples.html -image processing was a big help

#include "Game.h"


Game::Game() {
    std::cout << "constuctor called" << std::endl;
}

Game::Game(int screenWidth, int screenHeight)
{
    
    //-------------------------------------------------------------------------------------



    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {


        // Update
        //---------------------------------------------------------------------------------
        // TODO: Update your variables here

        // Draw
        //---------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        
            
        EndDrawing();
        //---------------------------------------------------------------------------------
    }
}

Game::~Game()
{
}
