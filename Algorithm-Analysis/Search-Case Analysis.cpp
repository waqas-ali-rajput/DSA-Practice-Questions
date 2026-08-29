#include <iostream>
using namespace std;

int linearSearchCount(const int array[], int size, int target, int& comparisons)
{
    comparisons = 0;

    for (int i = 0; i < size; i++)
    {
        comparisons++;
        if (array[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int array[100];
    for (int i = 0; i < 100; i++)
    {
        array[i] = i + 1;
    }

    int targets[] = {1, 50, 100, 999};
    const char* labels[] = {"First element", "Near middle", "Last element", "Missing value"};

    for (int i = 0; i < 4; i++)
    {
        int comparisons;
        int index = linearSearchCount(array, 100, targets[i], comparisons);

        cout << labels[i] << '\n';
        cout << "Target: " << targets[i] << '\n';
        cout << "Comparisons: " << comparisons << '\n';
        if (index == -1)
            cout << "Result: not found\n";
        else
            cout << "Result: found at index " << index << '\n';
        cout << '\n';
    }

    return 0;
}
