#include "Application.h"
#include "raylib.h"
#include <stdlib.h>

#include <cstdlib>
#include <iostream>

Application::Application()
{
	
}

Application::~Application()
{

}

void Application::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "Simple Tilemap");
	SetTargetFPS(60);

	Load();

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}

	Unload();
}

void Application::Load()
{
	// Task1:
	// Initialise all values in m_tiles array to a random
	// value between 0 and 5 exclusive;
	// -----------------------------------------------------
	
	// write your code here
	srand(time(NULL));


	for (int i = 0; i < ROWS * COLS; i ++) {//loops through all the tiles

		m_tiles[i] = rand() % 5;//and randomly assigns them a value from 0-5
		//std::cout << m_tiles[i];
	}
	// -----------------------------------------------------
}

void Application::Unload()
{

}

void Application::Update(float deltaTime)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();

		// Task 3:
		// TODO: Calculate row and col index based on the mouse positon
		int colIndex = mousePos.x / m_tileWidth;				  // uses mouse pos and divides the width of each tile to figure out where the mouse sits
		int rowIndex = (int)(mousePos.y / m_tileHeight) * ROWS;	  // does the same as above except multiplies by total rows, since the array is one dimentional, we also need every row 'above' to be included too

		// TODO: calculate the index of the tile clicked on based on the row/col index
		int tileIndex =  colIndex + rowIndex;//add them together to have the tile index


		if (tileIndex < ROWS * COLS) {//then, if the tiles exist within the screen
			m_tiles[tileIndex] += 1;//we add one to what colour they are
			if (m_tiles[tileIndex] >= 5)//if the colour ends up being larger than the largest colour
				m_tiles[tileIndex] = 0;//we make it loop
		}
	}
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	// Task2:
	// use a nested loop to iterate over rows and columns
	// Use raylib's DrawRect method to draw each tile in the array.
	// 	   use the row and col index multipled by m_tileHeight/m_tileWidth
	// 	   to calculate the x and y position for each rectangle.
	// 
	// change the color of the rect drawn based on the value of the tile.
	// 	   We have created a helper function you can use "GetTileColor"
	// --------------------------------------------------------------------
	// write your code here
	
	float xPos = 0;
	float yPos = 0;

	
	for (int rows = 0; rows < ROWS; rows++){		//
		yPos = rows * m_tileHeight;					//goes through one by one finding the y
		for (int cols = 0; cols < COLS; cols ++){	//within each row, is a number of cols which 
			xPos = cols* m_tileWidth;				//then is multiplied by tilewidth to find x positions
			Color color = GetTileColor(m_tiles[cols + (rows * ROWS)]); // pass in the tilevalue to get the colour
			DrawRectangle(xPos , yPos, m_tileWidth, m_tileHeight, color);//then put all the info together into the rectangle and then draw
		}
	}
	// --------------------------------------------------------------------

	EndDrawing();
}

Color Application::GetTileColor(int tileValue)
{
	switch (tileValue)
	{
	case 0: return WHITE;
	case 1: return RED;
	case 2: return GREEN;
	case 3: return BLUE;
	case 4: return YELLOW;
	}
	
	return BLACK;
}