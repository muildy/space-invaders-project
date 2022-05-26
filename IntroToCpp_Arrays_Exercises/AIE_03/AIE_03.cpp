

#include <iostream>
#include <string>

const int* BinarySearch(const int* arr, int count, int searchVal);
void TestResult(const int* result, int* const expected);


int main(int argc, char** argv)
{
	const int NUM_ITEMS = 8;
	int arr1[NUM_ITEMS] = { 1, 3, 5, 7, 9, 11, 13, 15 };

	// The numbers in the array are assumed to be sorted
	// search for the values 9, 1, 15, 0

	TestResult( BinarySearch(arr1, NUM_ITEMS, 9),  &arr1[4]   );
	TestResult( BinarySearch(arr1, NUM_ITEMS, 1),  &arr1[0]   );
	TestResult( BinarySearch(arr1, NUM_ITEMS, 15), &arr1[7]   );
	TestResult( BinarySearch(arr1, NUM_ITEMS, 0),  nullptr    );
	TestResult( BinarySearch(arr1, NUM_ITEMS, 16), nullptr    );


	return 0;
}

void TestResult(const int* result, int* const expected)
{
	if (result == expected)
	{
		std::cout << "PASS: result(" <<
			(result == nullptr ? "nullptr" : std::to_string(*result).c_str()) << ")" << std::endl;
		return;
	}

	std::cout << "FAIL: received(" <<
		(result == nullptr ? "nullptr" : std::to_string(*result).c_str()) << ") expected(" <<
		(expected == nullptr ? "nullptr" : std::to_string(*expected).c_str()) << ")" << std::endl;
}

	// This method should:
	//	- Return: nullptr if the value is not found
	//  - Return: pointer to the found value in the array
const int* BinarySearch(const int* arr, int count, int searchVal){
	// TODO: Implement a binary search
	// the array is assumed to be sorted

	int start = 0;
	int end = count-1;

	while (start <= end) {
		int searchInt = ((start + end) / 2);	//search int is the position the checked number is in the array
		int checkInt = (int)*(arr+searchInt);	//check int is the value that is being checked and compared to the searchVal

		if (checkInt == searchVal) {			//compares the value being looked at with the number being searched for
			return (arr + searchInt);			//if the numbers match, then the desired pointer is returned
		}
		else if (checkInt < searchVal) {		//if the checked int is smaller than the one we want
			start = searchInt + 1;				//we increase the start since we know it isnt there
		}
		else if (checkInt > searchVal) {		//opposite happens when the checked int is larger than the one we want
			end = searchInt - 1;
		}
	}
	

	return nullptr;//if the check yeilds no results, it returns a nullpointer
}



