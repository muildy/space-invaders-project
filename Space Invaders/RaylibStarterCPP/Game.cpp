//https://www.raylib.com/examples.html -image processing was a big help
#include "Game.h"


Game::Game()
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    deltaTime = 0;
    //-------------------------------------------------------------------------------------

    Player player = Player(screenWidth/2, screenHeight - (screenHeight/8));
    Bullet bullets = Bullet();

    EnemyManager enMngr = EnemyManager();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        deltaTime = GetFrameTime();                

        // Update
        //---------------------------------------------------------------------------------
        // TODO: Update your variables here
        player.update(deltaTime);


        if (IsKeyPressed(KEY_SPACE)) {
            std::cout << "SPACE" << std::endl;
            bullets.addBullet(player.posX, player.posY - 5, false);
        }

        bullets.update(deltaTime);
        enMngr.update(deltaTime);

        // Draw
        //---------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);

        bullets.draw();
        player.draw();
        enMngr.draw();

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
