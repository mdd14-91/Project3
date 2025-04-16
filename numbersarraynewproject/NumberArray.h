#ifndef NUMBER_ARRAY_H
#define NUMBER_ARRAY_H

//Number array class-This class implements an array of doubles. It contains the array, and provides operations
//for using the array: getting and setting values, and obtaining information such as highest value,
//lowest value, and average of all the values stored in the array.
class NumberArray {
private:

    //Constants:

    static const int MAX_SIZE = 10; //Default array size
    static constexpr double DEFAULT_ELEMENT = 10000.0; //Default value for out-of-bounds access

    //Class member variables:

    int dArray_Size = MAX_SIZE;
    double* dArray;

public:
    NumberArray(int array_size = MAX_SIZE); //Constructor
    ~NumberArray(); //Destructor

    void setNumber(int index, double value); //Set a number in the array 
    double getNumber(int index); //Retrieve a number from the array
    double getMinimum(); //Returns the lowest value element of the array
    double getMaximum(); //Returns the highest value element of the array
    double getAverage(); //Returns the average of all the elements in the array
    void printArray(); //Used to print all the elements in the array for testing purposes
};

#endif //end NumberArray.h
