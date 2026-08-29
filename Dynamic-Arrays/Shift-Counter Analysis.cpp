#include <iostream>
using namespace std;

const int MAX_SIZE = 10000;

void fillArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = i + 1;
    }
}

void copyArray(const int source[], int destination[], int size)
{
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}

int insertBeginningCount(int array[], int size)
{
    int shifts = 0;
    for (int i = size; i > 0; i--)
    {
        array[i] = array[i - 1];
        shifts++;
    }
    return shifts;
}

int insertMiddleCount(int array[], int size)
{
    int shifts = 0;
    int position = size / 2;
    for (int i = size; i > position; i--)
    {
        array[i] = array[i - 1];
        shifts++;
    }
    return shifts;
}

int insertEndCount(int array[], int size)
{
    return 0;
}

int deleteBeginningCount(int array[], int size)
{
    int shifts = 0;
    for (int i = 0; i < size - 1; i++)
    {
        array[i] = array[i + 1];
        shifts++;
    }
    return shifts;
}

int deleteMiddleCount(int array[], int size)
{
    int shifts = 0;
    int position = size / 2;
    for (int i = position; i < size - 1; i++)
    {
        array[i] = array[i + 1];
        shifts++;
    }
    return shifts;
}

int deleteEndCount(int array[], int size)
{
    return 0;
}

int main()
{
    int base[MAX_SIZE + 1];
    int temp[MAX_SIZE + 1];
    int sizes[] = {10, 100, 1000, 10000};

    for (int s = 0; s < 4; s++)
    {
        int n = sizes[s];
        fillArray(base, n);

        cout << "Size: " << n << '\n';

        copyArray(base, temp, n);
        cout << "Insert at beginning shifts: " << insertBeginningCount(temp, n) << '\n';

        copyArray(base, temp, n);
        cout << "Insert in middle shifts: " << insertMiddleCount(temp, n) << '\n';

        copyArray(base, temp, n);
        cout << "Insert at end shifts: " << insertEndCount(temp, n) << '\n';

        copyArray(base, temp, n);
        cout << "Delete from beginning shifts: " << deleteBeginningCount(temp, n) << '\n';

        copyArray(base, temp, n);
        cout << "Delete in middle shifts: " << deleteMiddleCount(temp, n) << '\n';

        copyArray(base, temp, n);
        cout << "Delete from end shifts: " << deleteEndCount(temp, n) << '\n';

        cout << '\n';
    }

    return 0;
}
