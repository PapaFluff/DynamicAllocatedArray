// Preprocessor directives required for this program
#include <iostream>

using namespace std;

// Function Prototypes -- reverseArray(Reverses elements in array), arrayExpander(Expands array by 2), elementShifter(Shifts elements in array)
int *reverseArray(int&, int []);
int *arrayExpander(int& , int []);
int *elementShifter(int&, int []);

// REVERSE ARRAY FUNCTION -- Copys the defaultlArray and reverses the elements into a new array
int *reverseArray(int& size, int defaultArray[])
{
    cout << endl;                                               // Ends line for clean format
    cout << "Here is the array reversed!" << endl;                 // Tells the user the array will be reversed
    
    int *backwardsArray = new int[size];     // Creates a new dynamic array
    
    // FOR LOOP, copies all the elements from the defaultArray into the new dynamic array, reversing them
    for (int j = 0; j < size; j++)
    {
        backwardsArray[j] = defaultArray[size - j - 1];         // Assigns backwardsArray to defaultArray and reverses the elements
        cout << backwardsArray[j] << "\t";                     // Outputs each element in the new dynamic array(backwardsArray)
    }
    
    return backwardsArray;  // Returns the pointer to the new array
}

// ARRAY EXPANDER FUNCTION -- creates a new array that is twice the size of defaultArray
int *arrayExpander(int& size, int defaultArray[])
{
    cout << endl;                                                        // Ends line for clean format
    cout << "Here is the array expanded by 2!" << endl;                 // Tells the user the array will be doubled
    
    int *twiceSizeArray = new int[size * 2];     // Creates a new dynamic array doubled by the original size
    
    // FOR LOOP, that assigns the elements from defaultArray into the new dynamic array, doubling the size and placing 0
    for (int e = 0; e < (size * 2); e++)
    {
        // IF statement, that assigns values from defaultArray into twiceSizeArray as long as the size is less
        if (e < size)
        {
            twiceSizeArray[e] = defaultArray[e];        // Assigns elements from defaultArray to twiceSizeArray
        }
        else    // if the size is bigger, places a 0
        {
            twiceSizeArray[e] = 0;                // Places a 0 at the element
        }
        
        cout << twiceSizeArray[e] << "\t";            // Outputs each element in the new dynamic array(twiceSizeArray)
    }
    
    return twiceSizeArray;  // Returns the pointer to the new array
}

// ELEMENT SHIFTER FUNCTION -- copies defaultArray and shifts the elements by 1
int *elementShifter(int& size, int defaultArray[])
{
    cout << endl;                                                   // Ends line for clean format
    cout << "Here are the elements shifted!" << endl;              // Tells user the elements will be shifted
    
    int *elementShiftArray = new int[size + 1];      // Creates a new dynamic array that is 1 size bigger
    elementShiftArray[0] = 0;                  // Sets the element 0 of the new array to 0
    
    cout << elementShiftArray[0] << "\t";       // Outputs element 0
    
    // FOR LOOP, goes through the program shifting each element by 1
    for (int k = 1; k <= size; k++)
    {
        elementShiftArray[k] = defaultArray[k - 1];        // Assigns elements from defaultArray to the new dynamic array, shifting the elements by 1
        cout << elementShiftArray[k] << "\t";             // Outputs each element in the new dynamic array(elementShiftArray)
    }
    
    return elementShiftArray;  // Returns the pointer to the new array
}

// MAIN FUNCTION -- The primary driver of the program(calls all the functions and sets up the defaultArray)
int main()
{
    int size = 0;                                                        // Declares and initializes size to 0
    cout << "What size do you want the array to be?" << endl;           // Prompts the user for size of array
    cin >> size;                                                       // USER INPUT HERE FOR SIZE
    
   int defaultArray[size];          // Creates a new array called defaultArray with user input determining the size
    
    int integer = 0;            // Declares and initializes element to 0
    
    // FOR LOOP, sets integers the user inputs into the default dynamically allocated array in a linear fashion
    for (int i = 0; i < size; ++i)
    {
        cout << "What integer do you want inside the array?" << endl;       // Prompts the user for desired integer
        cin >> integer;                                                    // USER INPUT FOR INTEGER
        
        defaultArray[i] = integer;            // Assigns the user values into the elements of the array
    }
    
    int *pointToReverse = nullptr;                                  // Defines a pointer in int main set to the null
    pointToReverse = reverseArray(size, defaultArray);             // Assigns pointer to call the reverseArray function
    cout << endl;                                       // Ends line for clean format
    int *pointToExpander = nullptr;                              // Defines a pointer in int main set to the null
    pointToExpander = arrayExpander(size, defaultArray);        // Assigns pointer to call the arrayExpander function
    cout << endl;                                      // Ends line for clean format
    int *pointToShifter = nullptr;                            // Defines a pointer in int main set to the null
    pointToShifter = elementShifter(size, defaultArray);     // Assigns pointer to call the elementShifter function
    cout << endl;                                      // Ends line for clean format
    
    // Free's dynamically allocated memory
    delete [] pointToReverse;
    delete [] pointToExpander;
    delete [] pointToShifter;
}
