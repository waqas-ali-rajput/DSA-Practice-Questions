#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

int linearSearch(const vector<int>& a, int target, long long& comp)
{
    comp = 0;

    for (int x : a)
    {
        comp++;

        if (x == target)
            return x;
    }

    return -1;
}

int binarySearch(const vector<int>& a, int target, long long& comp)
{
    comp = 0;

    int low = 0;
    int high = a.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        comp++;

        if (a[mid] == target)
            return a[mid];

        if (target < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

double measureLinear(const vector<int>& a, int target, long long& comp)
{
    double total = 0;

    for (int i = 0; i < 5; i++)
    {
        auto start = high_resolution_clock::now();

        volatile int result = linearSearch(a, target, comp);

        auto end = high_resolution_clock::now();

        total += duration<double, micro>(end - start).count();
    }

    return total / 5;
}

double measureBinary(const vector<int>& a, int target, long long& comp)
{
    double total = 0;

    for (int i = 0; i < 5; i++)
    {
        auto start = high_resolution_clock::now();

        volatile int result = binarySearch(a, target, comp);

        auto end = high_resolution_clock::now();

        total += duration<double, micro>(end - start).count();
    }

    return total / 5;
}

int main()
{
    vector<int> sizes = {1000, 10000, 100000, 1000000};

    cout << fixed << setprecision(3);

    cout << "Size\tTarget\t\tLinear(C)\tLinear Avg(us)"
         << "\tBinary(C)\tBinary Avg(us)\n";

    cout << "-------------------------------------------------------------------------------\n";

    for (int n : sizes)
    {
        vector<int> a(n);

        for (int i = 0; i < n; i++)
            a[i] = i;

        int targets[] = {a[0], a[n / 2], a[n - 1], -1};
        string names[] = {"First", "Middle", "Last", "Absent"};

        for (int i = 0; i < 4; i++)
        {
            long long linearComp, binaryComp;

            double linearTime =
                measureLinear(a, targets[i], linearComp);

            double binaryTime =
                measureBinary(a, targets[i], binaryComp);

            cout << n << "\t"
                 << names[i] << "\t\t"
                 << linearComp << "\t\t"
                 << linearTime << "\t\t"
                 << binaryComp << "\t\t"
                 << binaryTime << "\n";
        }
    }

    return 0;
}
