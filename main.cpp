#include <iostream>
#include <fstream>  // For file operations
#include "functions.h"

using namespace std;

int main() {
    // Initialize the array and size
    int arr[MAX_SIZE];
    int size = 0;  // Start with size 0 and will update after reading file

    // Open the input file
    ifstream inputFile("A1input.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open the input file." << endl;
        return 1; // Exit with error code
    }

    // Read the file into the array
    int value;
    while (inputFile >> value) {
        if (size >= MAX_SIZE) {
            cerr << "Error: Array size exceeds maximum limit." << endl;
            return 1; // Exit with error code
        }
        arr[size++] = value;
    }

    inputFile.close(); // Close the file

    // Example 1: Modify a value in the array
    try {
        int oldValue;
        int newValue = 100;
        int index = 10;  // Example index
        modifyValue(arr, index, newValue, oldValue);
        cout << "Success: Value at index " << index << " was changed from " << oldValue << " to " << newValue << "." << endl;
    } catch (const ArrayException& e) {
        cout << "Error: " << e.what() << " - Unable to modify value." << endl;
    }

    // Example 2: Append a new value to the array
    try {
        int newValue = 101;
        if (appendValue(arr, size, newValue)) {
            cout << "Success: Value " << newValue << " was added to the array. New size is " << size << "." << endl;
        }
    } catch (const ArrayException& e) {
        cout << "Error: " << e.what() << " - Could not append value." << endl;
    }

    // Example 3: Update or remove a value from the array
    try {
        int index = 5;  // Example index
        bool remove = true; // Set to false if you want to replace with 0 instead of removing
        updateOrRemove(arr, size, index, remove);
        if (remove) {
            cout << "Success: Value at index " << index << " has been removed." << endl;
        } else {
            cout << "Success: Value at index " << index << " has been replaced with 0." << endl;
        }
    } catch (const ArrayException& e) {
        cout << "Error: " << e.what() << " - Update or removal operation failed." << endl;
    }

    // Display the final state of the array
    cout << "Final Array State: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}