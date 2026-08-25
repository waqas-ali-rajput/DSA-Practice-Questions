#include <iostream>
using namespace std;

void displayArray(const int array[], int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
}

void removeAllOccurrences(int array[], int& size, int target)
{
    int write = 0;

    for (int read = 0; read < size; read++)
    {
        if (array[read] != target)
        {
            array[write] = array[read];
            write++;
        }
    }

    size = write;
}

int main()
{
    int array[] = {4, 2, 4, 7, 4, 9};
    int size = 6;
    int target = 4;

    cout << "Original array: ";
    displayArray(array, size);
    cout << '\n';

    removeAllOccurrences(array, size, target);

    cout << "Target: " << target << '\n';
    cout << "Result: ";
    displayArray(array, size);
    cout << '\n';

    return 0;
}