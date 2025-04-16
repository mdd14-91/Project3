#include "NumberArray.h"
#include <iostream>
using namespace std;


//:NumberArray-Constructor
//inputs=(optional) size of array user wants to create, integer
//output=none
//preconditions=none. This is the class constructor.
//postcondition= the array is created. If no array or wrong one then it shoots out error message and
// stops loop
 NumberArray::NumberArray(int array_size) {

	//Save the size the user requested.
	dArray_Size = array_size;
	
		dArray = new double[array_size];

		for (int i = 0; i < array_size; i++)
			dArray[i] = 0.0;
	
}

//~NumberArray-Destructor
//inputs=none. This is the class destructor.
//output=deallocates array
//preconditions=none. This is the class destructor.
//postcondition=deallocates array
 NumberArray::~NumberArray() {

	delete[] dArray;

	cout << "Destructor is running." << endl;
}

//SetNumber-Stores a number in any element of the array.
//inputs=the array index and the value to store at that index
//output=none
//preconditions=the array must first be created by the constructor.
//postcondition=the value is stored at the specified index, or, if the index is
//out of bounds, an error message is displayed.
  void NumberArray::setNumber(int index, double value) {

	// Check if the index is less than or equal to 0; if not, write an error message. Else, store the value.
	if ((index < 0) || (index >= dArray_Size))
		cout << "Index of " << index << " is out of the bounds of the array. Number not stored." << endl;
	else
		dArray[index] = value;
}

//:getNumber-Retrieves a value from the specified location in the array. 
//inputs=the array index of the value that should be returned as integer
//output=the value in the array at the index specified by the user or if the index is
//out of bounds, a default value
//preconditions=the array must first be created by the constructor.
//postcondition=the value is retrieved from the specified index location in the array, or, if the 
//index is out of bounds, an error message is displayed and a default value is returned as type double.
 double NumberArray::getNumber(int index) {

	if ((index < 0) || (index >= dArray_Size)) {

		cout << "Index of " << index << " is out of the bounds of the array. Returning the default value." << endl;
		return DEFAULT_ELEMENT;
	}
	else
		return dArray[index];
}

//getMinimum Definition-Finds and returns the smallest value in the array.The function returns the value.
//This is a value that is calculated when needed so it doesn’t get stale if the array numbers change.
//inputs=none
//output=the smallest number in the array
//preconditions=the array must first be created by the constructor.
//postcondition=the minimum value is returned, or, if it has a size <= 0 then
//an error message is displayed and a default value is returned.
double NumberArray::getMinimum() {

	double min_value = 0.0;

	if (dArray_Size > 0) {
		min_value = dArray[0];
		for (int i = 1; i < dArray_Size; i++) {
			if (dArray[i] < min_value) {
				min_value = dArray[i];
			}
		}
		return min_value;
	}
	else {
		cout << "The array is size 0. Returning the default value." << endl;
		return DEFAULT_ELEMENT;
	}
}

//getMaximum-Finds and returns the maximum value in the array.The function returns the value rather than the index where it is stored.
//This is a value that is calculated when needed so it doesn’t get stale if the numbers in the array change.
//inputs=none
//output=the largest (maximum) value number in the array
//preconditions=the array must first be created by the constructor.
//postcondition=the maximum value is returned, or, if the array wasn't created, i.e., it has a size <= 0,
//an error message is displayed and a default value is returned.
double NumberArray::getMaximum() {

	double max_value = 0.0;

	if (dArray_Size > 0) {
		max_value = dArray[0];
		for (int i = 1; i < dArray_Size; i++) {
			if (dArray[i] > max_value) {
				max_value = dArray[i];
			}
		}
		return max_value;
	}
	else {
		cout << "The array is size 0. Returning the default value." << endl;
		return DEFAULT_ELEMENT;
	}
}

//getAverage-Calculates and returns the average of the values in the array.This is a value that is calculated when needed so it doesn’t
//get stale if the numbers in the array change.
//inputs=none
//output=the average value of all the numbers in the array
//preconditions=the array must first be created by the constructor.
//postcondition=the average value is returned, or, if the array wasn't created, i.e., it has a size <= 0,
//an error message is displayed and a default value is returned.
double NumberArray::getAverage() {

	double sum = 0.0;

	if (dArray_Size > 0) {
		for (int i = 0; i < dArray_Size; i++) {
			sum = sum + dArray[i];
		}
		return (sum / dArray_Size);
	}
	else {
		cout << "The array is size 0. Returning the default value." << endl;
		return DEFAULT_ELEMENT;
	}
}

//PrintArray function-Used to print all the elements in the array for testing purposes
//inputs=none
//output=none
//preconditions=the array must first be created by the constructor.
//postcondition=the array is printed, or, if the array wasn't created, i.e., it has a size <= 0,
//nothing happens.
void NumberArray::printArray() {

	if (dArray_Size > 0) {
		for (int i = 0; i < dArray_Size; i++) {
			cout << dArray[i] << " ";
		}
		cout << endl;
	}
}
