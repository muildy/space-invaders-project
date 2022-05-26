//https://www.raylib.com/examples.html -image processing was a big help

#include "Game.h"


Game::Game() {
    std::cout << "constuctor called" << std::endl;
}

Game::Game(int screenWidth, int screenHeight)
{
    
    Player* player = new Player(screenWidth / 2, screenHeight - (screenHeight / 8), 10);

    Enemies* enemy = new Enemies(screenWidth / 2, (screenHeight / 8), 10);
    //--------------------------------------------------------------------------------------



    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {


        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        Vector2 ve = { screenWidth/2,screenHeight /2};
        
        player->update();
        enemy->update(ve);


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        player->draw();
        enemy->draw();

        EndDrawing();
        //---------------------------------------------------------------------------------- 
    }
}

Game::~Game()
{
}
