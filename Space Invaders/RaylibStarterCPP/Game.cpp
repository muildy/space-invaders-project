//https://www.raylib.com/examples.html -image processing was a big help
#include "Game.h"


Game::Game()
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    
    //new std::vector<Bullet>(bullets);
    //-------------------------------------------------------------------------------------

    Player player = Player(screenWidth/2, screenHeight - (screenHeight/8));




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
            Bullet* y = new Bullet(player.posX, player.posY, false);
            bullets.push_back(y);
        }

        if (bullets.size() > 0) {
            for (int i = 0; i < bullets.size(); i++) {
                bullets[i]->update(deltaTime);

                if ((bullets[i]->posX >= GetScreenWidth() || bullets[i]->posX <= 0) || (bullets[i]->posY <= 0 || bullets[i]->posY >= GetScreenHeight())) {
                    
                    Bullet* temp = bullets[i];
                    bullets.erase(bullets.begin() + i);
                    delete(temp);
                }
            }
        }


        if (enemies.size() > 0) {
            for (int i = 0; i < enemies.size(); i++) {
                bullets[i]->update(deltaTime);

                if ((enemies[i]->posX >= GetScreenWidth() || enemies[i]->posX <= 0) || (enemies[i]->posY <= 0 || enemies[i]->posY >= GetScreenHeight())) {
                    
                    Enemy* temp = enemies[i];
                    enemies.erase(enemies.begin() + i);
                    delete(temp);
                }
            }
        }




        // Draw
        //---------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        if (bullets.size() > 0) {
            for (Bullet* b : bullets) {
                b->draw();
            }
        }
        if (enemies.size() > 0) {
            for (Bullet* b : bullets) {
                b->draw();
            }
        }
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
