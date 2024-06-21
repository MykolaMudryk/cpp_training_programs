#include <iostream>
using namespace std;

inline void printArray(int* arr, int arraySize)
{
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

inline void bubbleSorting(int* arr, int n) 
{
    bool swapped;
    for (size_t i = 0; i < n-1; i++)
    {
        swapped = false;
        for (size_t j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
               int temp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = temp;
               swapped = true; 
            }
        }
        if (!swapped)
            break;
        
    }
    
}

int main() {
    int arraySize;
    cout << "Введіть розмір масиву: ";
    cin >> arraySize;

    int* myArray = new int[arraySize];

    for (int i = 0; i < arraySize; i++) {
        cout << "Введіть усі значення масиву: ";
        cin >> myArray[i];
    }
    
    bubbleSorting(myArray, arraySize);
    cout << "Відсортований масив: ";
    printArray(myArray, arraySize);
    
    delete[] myArray;
    return 0;
}
