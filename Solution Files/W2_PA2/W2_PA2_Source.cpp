//This program copies and expands an array of integers.
//Note: initial array values were not specified in assignment requirements,
//so I have initialized this array with a series of ten constant integers.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Function prototypes
int* expandArray(int[], int);
void showArray(int[], int);

int main()
{
	const int ARRAY_SIZE = 10;
	int array[ARRAY_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *ptr = nullptr;

	cout << "The initial array's contents are as follows:" << endl << endl;

	//Display the contents of the first array
	showArray(array, ARRAY_SIZE);

	//Set the address of the pointer to the pointer to the new array as returned by the function
	ptr = expandArray(array, ARRAY_SIZE);

	cout << "After doubling the size of the array," << endl
		<< "and initializing its remaining elements to 0," << endl
		<< "the new array's contents are as follows:" << endl << endl;

	//Display the contents of the new double-sized array
	showArray(ptr, (ARRAY_SIZE * 2));

	cout << "Thank you for using our program!" << endl << endl;
	char ch;
	ch = cin.get();

	return 0;
}

int* expandArray(int firstArray[], int size)
{
	int newArraySize = size * 2;
	int *newArray = nullptr;

	newArray = new int[newArraySize];

	//Copy the contents of the first array into the first half of the new array
	for (int count = 0; count < size; count++)
	{
		*(newArray + count) = firstArray[count];
	}

	//Set the values in the second half of the new array to 0
	for (int index = size; index < newArraySize; index++)
	{
		*(newArray + index) = 0;
	}

	return newArray;
}

void showArray(int array[], int size)
{
	for (int count = 0; count < size; count++)
		cout << array[count] << " ";
	cout << endl << endl;
}