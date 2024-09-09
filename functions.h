#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <exception> // For std::exception

const int MAX_SIZE = 100;

// Function declarations
int findIndex(const int arr[], int size, int value);
void modifyValue(int arr[], int index, int newValue, int &oldValue);
bool appendValue(int arr[], int &size, int newValue);
void updateOrRemove(int arr[], int &size, int index, bool remove);

// Exception class for array operations
class ArrayException : public std::exception {
public:
    // Override the what() method from std::exception
    const char* what() const noexcept override;
};

#endif // FUNCTIONS_H
