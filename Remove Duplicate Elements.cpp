#include <iostream>
using namespace std;

int removeDuplicates(int array[], int size)
{
    int newSize = 0;

    for (int i = 0; i < size; i++)
    {
        bool found = false;

        for (int j = 0; j < newSize; j++)
        {
            if (array[j] == array[i])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            array[newSize] = array[i];
            newSize++;
        }
    }

    return newSize;
}

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

int main()
{
    int array[] = {5, 2, 5, 3, 2, 7};
    int size = 6;

    cout << "Original array: ";
    displayArray(array, size);
    cout << '\n';

    size = removeDuplicates(array, size);

    cout << "Result: ";
    displayArray(array, size);
    cout << '\n';

    cout << "Time complexity: O(n^2)\n";
    cout << "Auxiliary space: O(1)\n";

    return 0;
}