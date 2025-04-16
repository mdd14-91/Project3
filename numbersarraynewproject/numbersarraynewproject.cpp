#include "NumberArray.h"
#include <iostream>
#include <random>

using namespace std;
//Main function-
//creates 2 arrays, 1 of size 10 and another of size 15 all with values preinitialized to 0.0.
//uses a mutator to fill out the values of the size 15 array and another to demonstrate out of bounds behavior
//accessess previously filled out array at index 5, then attempts to access out of bound index.
// Reveals the minimum, maximum and average number of the filled out array.
//Then deconstructs the arrays by deallocating the memory with the destructor functions.


	// Constants
const int ARRAY_SIZE = 15;
const double MIN = 0.1; // Minimum random value
const double MAX = 99.9; // Maximum random value

// NumberArray class objects
NumberArray defaultSizeArray = NumberArray();
NumberArray parameterSizeArray = NumberArray(ARRAY_SIZE);
int main() {


	

	// Random number engine
	random_device engine;

	// Distribution object for rando number generation
	uniform_real_distribution<double>numberValue(MIN, MAX);

	cout << "---- - Test constructors---- -" << endl;

	cout << "From default constructor: Array of size 10" << endl;
	cout << fixed;
	cout.precision(1);
	defaultSizeArray.printArray();
	cout << endl;

	cout << "From constructor with parameters : Array of size 15" << endl;
	parameterSizeArray.printArray(); 
	cout << endl;

	cout << "---- - Test mutator---- -" << endl;

	for (int i = 0; i < ARRAY_SIZE; i++)
		parameterSizeArray.setNumber(i, numberValue(engine));
	cout << endl;

	cout << "Array filled with numbers :" << endl;
	parameterSizeArray.printArray();
	cout << endl;

	cout << "Trying to set a number with an out of bounds index(20) :" << endl;
	//Numbers below randomly chosen for testing.
	parameterSizeArray.setNumber(20, 99.9);
	cout << endl;

	cout << "---- - Test accessors _____" << endl;

	cout << "Access item at index 5 : " << parameterSizeArray.getNumber(5) << endl << endl;
	cout << "Access item at index 20 (out of bounds) : " << parameterSizeArray.getNumber(20) << endl << endl;

	cout << "The minimum value in the array is : " << parameterSizeArray.getMinimum() << endl;
	cout << "The maximum value in the array is : " << parameterSizeArray.getMaximum() << endl;
	cout << "The average of the values in the array is : " << parameterSizeArray.getAverage() << endl << endl;
}