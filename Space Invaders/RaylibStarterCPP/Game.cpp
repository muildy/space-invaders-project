//https://www.raylib.com/examples.html -image processing was a big help

#include "Game.h"
#include "Player.h"

Game::Game()
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    
    //-------------------------------------------------------------------------------------

    Player player = Player(screenWidth/2,screenHeight*(1/8));

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {


        // Update
        //---------------------------------------------------------------------------------
        // TODO: Update your variables here
        player.update();

        // Draw
        //---------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        player.draw();
            
        EndDrawing();
        //---------------------------------------------------------------------------------
    }
}

Game::~Game()
{
}

int Game::score(int incr)
{
    incr++;
    return incr;
}

void Game::display()
{
    //DrawRectangleLines(10,10,);
    //DrawText("START", startbutton.x + 5 + (rand() % 3), startbutton.y + 5 + (rand() % 2), 20, WHITE);
}
