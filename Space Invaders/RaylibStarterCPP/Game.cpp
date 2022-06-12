//https://www.raylib.com/examples.html -image processing was a big help for the menu buttons
#include "Game.h"


Game::Game()
{
    score = 0;
    fireRateEnemy = 0;
    fireRatePlayer = 10;
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
        fireRateEnemy++;
        fireRatePlayer++;
        std::cout << TextFormat("fireRateEnemy: %08i \n", fireRateEnemy);
        std::cout << TextFormat("fireRatePlayer: %08i \n", fireRatePlayer);

        deltaTime = GetFrameTime();                

        // Update
        //---------------------------------------------------------------------------------
        // TODO: Update your variables here
        player.update(deltaTime);

        //granted space is being pressed and fireRatePlayer is larger than 5, it adds a player bullet to the bullet array 
        if (IsKeyPressed(KEY_SPACE) && fireRatePlayer > 10) {
            fireRatePlayer = 0;
            bullets.addBullet(player.posX, player.posY - 15, false);
        }


        bullets.update(deltaTime);
        enMngr.update(deltaTime);
        
        

        
        //bullet - player collision test if the player has collided, they die
        if (bullets.bulletCheck(player.posX, player.posY, player.m_size , true/*because player is being checked*/) || enMngr.gameOver) {
            enMngr.depopulate();
            bullets.clearBullet();
            DeathScreen ded = DeathScreen(score);
            continue;
        }

        //collision detection for enemies, goes through each enemy and checks if each bullet is within the enemies hitcircle and if the bullet is an enemies
        for (int i = 0; i < enMngr.enemies.size(); i++) {
            int enSize = enMngr.enemies[i]->m_size/2;
            if (bullets.bulletCheck(
                enMngr.enemies[i]->posX + enSize,
                enMngr.enemies[i]->posY + enSize, enSize, false/*because enemy is being checked*/)) {
                
                enMngr.removeEnemy(i);
                Score();
            }
        }

        //respawning enemies if player kills all of them
        //clears all the bullets so the player cant just have bullets instakill enemies
        if (enMngr.enemies.size() == 0) {
            bullets.clearBullet();
            enMngr.repopulate();
        }

        //enemy shoot part
        if (fireRateEnemy > 50) {
            fireRateEnemy = 0;
            randIndex = rand() % enMngr.enemies.size();
            bullets.addBullet(enMngr.enemies[randIndex]->posX, enMngr.enemies[randIndex]->posY, true);
        }
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
