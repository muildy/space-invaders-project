//https://www.raylib.com/examples.html -image processing was a big help
#include "Game.h"
/// <summary>
/// Issues:
/// i dont think enemies are being properly removed since the mem usage only increases
/// player is still a tiny circle at the bottom of screen
/// need restrictions on how fast player can shoot
/// also needs restrictions for player movement
/// </summary>
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
            bullets.addBullet(player.posX, player.posY - 50, false);
        }
        if (IsKeyPressed(KEY_E)) {
            bullets.addBullet(GetMouseX(), GetMouseY(), true);
        }

        bullets.update(deltaTime);
        enMngr.update(deltaTime);
        
        //bullet - player collision test
        if (bullets.bulletCheck(player.posX, player.posY, player.m_size)) {
            std::cout << "playerhit" << std::endl; break;
        }

        
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

int Game::Score()
{
    score++;
    return score;
}

void Game::display()
{
    DrawText(TextFormat("Score: %04i", score), 10, 10, 20, DARKGRAY);

}
