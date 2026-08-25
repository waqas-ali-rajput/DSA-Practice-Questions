#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int binarySearch(const vector<int>& values, int target, int& comparisons)
{
    comparisons = 0;

    int low = 0;
    int high = values.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        comparisons++;

        if (values[mid] == target)
            return mid;

        else if (target < values[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

void printArray(const vector<int>& values)
{
    for (int x : values)
        cout << x << " ";

    cout << endl;
}

int main()
{
    vector<int> A = {
        137, 680, 451, 237, 125, 478, 552,
        672, 154, 12, 67, 952, 47, 68
    };

    cout << "Original array:\n";
    printArray(A);

    // Sort array
    sort(A.begin(), A.end());

    cout << "\nSorted array:\n";
    printArray(A);

    // Target
    int target = 12;
    int comparisons;

    int index = binarySearch(A, target, comparisons);

    cout << "\nTarget: " << target << endl;
    cout << "Index: " << index << endl;
    cout << "Comparisons: " << comparisons << endl;

    return 0;
}