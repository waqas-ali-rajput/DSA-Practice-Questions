#include <iostream>
using namespace std;

int linearSearch(const int values[], int size, int target, int& comparisons)
{
    comparisons = 0;
    for (int i = 0; i < size; i++)
    {
        comparisons++;
        if (values[i] == target)
            return i;
    }
    return -1;
}

int main()
{
    int A[] = {54, 76, 12, -48, -25, 75, 37, 2, 7, 8};
    int size = sizeof(A) / sizeof(A[0]);

    int comparisons;

    int target1 = 37;
    int index1 = linearSearch(A, size, target1, comparisons);
    cout << "Target: " << target1 << "\nIndex: " << index1 << "\nComparisons: " << comparisons << "\n\n";

    int target2 = 100;
    int index2 = linearSearch(A, size, target2, comparisons);
    cout << "Target: " << target2 << "\nIndex: " << index2 << "\nComparisons: " << comparisons << "\n";

    return 0;
}
