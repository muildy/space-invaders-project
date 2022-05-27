
#include <iostream>




int main(int argc, char** argv)
{
	const int ROWS = 3;
	const int COLS = 5;

	const char* grid2D[ROWS][COLS] =
	{
		{ "a0", "a1", "a2", "a3", "a4" },
		{ "b0", "b1", "b2", "b3", "b4" },
		{ "c0", "c1", "c2", "c3", "c4" },
	};


	// Task 1:
	// Print all values in the grid using nested loops to iterate over rows and columns.
	// Expected output:
	//		a0, a1, a2, a3, a4, 
	//		b0, b1, b2, b3, b4,
	//		c0, c1, c2, c3, c4,
	// ------------------------------------------------------------------------
													//
	for (int row = 0; row < ROWS; row++) {			//loops through all the rows
		for (int col = 0; col < COLS; col++) {		//within each row is 5 columns, which we then loop through
			std::cout << grid2D[row][col] << ", ";	//then, we print out each column in each row
		}											//
		std::cout << std::endl;						//once a column is completed, we print an end line
	}												//
	std::cout << std::endl;							//


	// ------------------------------------------------------------------------



	// Task 2:
	// Print all values in the grid using a single loop
	// Expected output:
	//		a0, a1, a2, a3, a4, b0, b1, b2, b3, b4, c0, c1, c2, c3, c4,
	// ------------------------------------------------------------------------

	for (int index = 0; index < ROWS * COLS; index++)
	{
		// TODO: convert "index" to a "rowIndex" and "colIndex" value
		int rowIndex = index / 5;//there are 5 columns, and max index is = to row * col, so divide index by cols, and you get rows
		int colIndex = index % 5;//divides and returns remainder, so it counts up to 4 before returning 0


		// use the resulting row and column index to print the value
		std::cout << grid2D[rowIndex][colIndex] << ", ";
	}

	// ------------------------------------------------------------------------
	std::cout << std::endl << std::endl;
	// ------------------------------------------------------------------------


	const char* grid1D[ROWS*COLS] =
	{
		"a0", "a1", "a2", "a3", "a4",
		"b0", "b1", "b2", "b3", "b4",
		"c0", "c1", "c2", "c3", "c4"
	};

	// Task 3:
	// using a nested loop to iterate over rows/columns
	// convert the row and column index to a single index value to print the values
	// of grid1D
	// Expected output:
	//		a0, a1, a2, a3, a4, 
	//		b0, b1, b2, b3, b4,
	//		c0, c1, c2, c3, c4,
	// ------------------------------------------------------------------------
	//		0	1	2	3	4
	//		5	6	7	8	9
	//		10	11	12	13	14


	for (int rowIndex = 0; rowIndex < ROWS; rowIndex++)
	{
		for (int colIndex = 0; colIndex < COLS; colIndex++)
		{
			// TODO: calculate "index" based on rowIndex/colIndex value
			int index = colIndex + (rowIndex * 5);//add the current column to the current row multiplied by the amount of values in the row

			// use the resulting index to print the value
			std::cout << grid1D[index] << ", ";
		}
		std::cout << std::endl;
	}

	// ------------------------------------------------------------------------

}

