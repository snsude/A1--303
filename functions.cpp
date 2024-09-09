#include "functions.h"
#include <iostream>

using namespace std;

// Function to find the index of a value in the array
int findIndex(const int arr[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1; // Value not found
}

// Function to modify the value at a specific index
void modifyValue(int arr[], int index, int newValue, int &oldValue) {
    if (index < 0 || index >= MAX_SIZE) {
        throw ArrayException(); // Index out of bounds
    }
    oldValue = arr[index];
    arr[index] = newValue;
}

// Function to append a new value to the end of the array
bool appendValue(int arr[], int &size, int newValue) {
    if (size >= MAX_SIZE) {
        throw ArrayException(); // Array is full
    }
    arr[size] = newValue;
    ++size;
    return true;
}

// Function to update or remove a value at a specific index
void updateOrRemove(int arr[], int &size, int index, bool remove) {
    if (index < 0 || index >= size) {
        throw ArrayException(); // Index out of bounds
    }
    if (remove) {
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size;
    } else {
        arr[index] = 0; // Replace with 0
    }
}

// Implementation of ArrayException class's what() method
const char* ArrayException::what() const noexcept {
    return "Array operation error.";
}
