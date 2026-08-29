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

void copyArray(const int source[], int destination[], int size)
{
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}

void rotateLeftOne(int array[], int size)
{
    if (size <= 1)
    {
        return;
    }

    int first = array[0];
    for (int i = 0; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    array[size - 1] = first;
}

void rotateRightOne(int array[], int size)
{
    if (size <= 1)
    {
        return;
    }

    int last = array[size - 1];
    for (int i = size - 1; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = last;
}

void rotateLeftK(int array[], int size, int k)
{
    if (size <= 1)
    {
        return;
    }

    k = k % size;
    for (int i = 0; i < k; i++)
    {
        rotateLeftOne(array, size);
    }
}

void rotateRightK(int array[], int size, int k)
{
    if (size <= 1)
    {
        return;
    }

    k = k % size;
    for (int i = 0; i < k; i++)
    {
        rotateRightOne(array, size);
    }
}

int main()
{
    int emptySize = 0;
    int emptyArray[1] = {0};

    int oneArray[] = {99};
    int oneSize = 1;

    int base[] = {1, 2, 3, 4, 5};
    int size = 5;
    int temp[5];

    cout << "Empty array:\n";
    cout << "Original: ";
    displayArray(emptyArray, emptySize);
    cout << '\n';
    rotateLeftOne(emptyArray, emptySize);
    cout << "After left one: ";
    displayArray(emptyArray, emptySize);
    cout << '\n';
    rotateRightOne(emptyArray, emptySize);
    cout << "After right one: ";
    displayArray(emptyArray, emptySize);
    cout << "\n\n";

    cout << "One-element array:\n";
    cout << "Original: ";
    displayArray(oneArray, oneSize);
    cout << '\n';
    rotateLeftOne(oneArray, oneSize);
    cout << "After left one: ";
    displayArray(oneArray, oneSize);
    cout << '\n';
    rotateRightOne(oneArray, oneSize);
    cout << "After right one: ";
    displayArray(oneArray, oneSize);
    cout << "\n\n";

    cout << "k = 0:\n";
    copyArray(base, temp, size);
    rotateLeftK(temp, size, 0);
    cout << "Left 0: ";
    displayArray(temp, size);
    cout << '\n';
    copyArray(base, temp, size);
    rotateRightK(temp, size, 0);
    cout << "Right 0: ";
    displayArray(temp, size);
    cout << "\n\n";

    cout << "k = size:\n";
    copyArray(base, temp, size);
    rotateLeftK(temp, size, size);
    cout << "Left size: ";
    displayArray(temp, size);
    cout << '\n';
    copyArray(base, temp, size);
    rotateRightK(temp, size, size);
    cout << "Right size: ";
    displayArray(temp, size);
    cout << "\n\n";

    cout << "k > size:\n";
    copyArray(base, temp, size);
    rotateLeftK(temp, size, 7);
    cout << "Left 7: ";
    displayArray(temp, size);
    cout << '\n';
    copyArray(base, temp, size);
    rotateRightK(temp, size, 7);
    cout << "Right 7: ";
    displayArray(temp, size);
    cout << '\n';

    return 0;
}
