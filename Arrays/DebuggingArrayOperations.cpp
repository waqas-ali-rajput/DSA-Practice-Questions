#include <iostream>
using namespace std;

bool insertElement(int array[], int& size, int capacity, int position, int value)
{
    if (size >= capacity)
    {
        return false;
    }

    if (position < 0 || position > size)
    {
        return false;
    }

    for (int i = size; i > position; i--)
    {
        array[i] = array[i - 1];
    }

    array[position] = value;
    size++;

    return true;
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
    int array[5] = {10, 20, 30};
    int size = 3;

    if (insertElement(array, size, 5, 1, 99))
    {
        cout << "After insertion: ";
        displayArray(array, size);
        cout << '\n';
    }
    else
    {
        cout << "Insertion failed.\n";
    }

    return 0;
}
