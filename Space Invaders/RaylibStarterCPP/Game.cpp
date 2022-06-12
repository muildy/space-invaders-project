//https://www.raylib.com/examples.html -image processing was a big help for the menu buttons
#include "Game.h"


Game::Game()
{
    score = 0;
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
            bullets.addBullet(player.posX, player.posY - 15, false);
        }
        //cheat bullet for testing
        if (IsKeyPressed(KEY_E)) {
            bullets.addBullet(GetMouseX(), GetMouseY(), true);
        }

        bullets.update(deltaTime);
        enMngr.update(deltaTime);
        
        //enemy shoot part


        //bullet - player collision test
        if (bullets.bulletCheck(player.posX, player.posY, player.m_size) || enMngr.gameOver) {
            enMngr.depopulate();
            DeathScreen ded = DeathScreen(score);
            continue;
        }
        //collision detection for enemies, goes through each enemy and checks if each bullet is within
        for (int i = 0; i < enMngr.enemies.size(); i++) {
            if (bullets.bulletCheck(enMngr.enemies[i]->posX, enMngr.enemies[i]->posY, enMngr.enemies[i]->m_size)) {                
                std::cout << "enemyhit" << std::endl;
                enMngr.removeEnemy(i);
                Score();
            }
        }

        if (enMngr.enemies.size() == 0)
            enMngr.repopulate();
        // Draw
        //---------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);

        bullets.draw();
        player.draw();
        enMngr.draw();
        display();
        EndDrawing();
        //---------------------------------------------------------------------------------
    }
}

Game::~Game()
{
}
//increments then returns score
int Game::Score()
{
    score++;
    return score;
}

void Game::display()
{
    DrawText(TextFormat("Score: %04i", score), 10, 10, 20, DARKGRAY);
}
