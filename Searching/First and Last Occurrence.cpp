#include <iostream>
using namespace std;

int findFirstOccurrence(const int array[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int findLastOccurrence(const int array[], int size, int target)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if (array[i] == target)
        {
            return i;
        }
    }

    return -1;
}

void testCase(const int array[], int size, int target, const char* title)
{
    cout << title << '\n';
    cout << "Target: " << target << '\n';
    cout << "First occurrence: " << findFirstOccurrence(array, size, target) << '\n';
    cout << "Last occurrence: " << findLastOccurrence(array, size, target) << '\n';
    cout << '\n';
}

int main()
{
    int a1[] = {4, 2, 4, 7, 4, 9};
    int a2[] = {1, 2, 3, 4};
    int emptyArray[1] = {0};
    int emptySize = 0;

    testCase(a1, 6, 4, "Duplicate array, target exists");
    testCase(a2, 4, 5, "Array without target");
    testCase(emptyArray, emptySize, 10, "Empty array");

    return 0;
}
