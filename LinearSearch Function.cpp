#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Linear Search Function
int linearSearch(const int values[], int size, int target, int& comparisons)
{
    comparisons = 0;

    for (int i = 0; i < size; i++)
    {
        comparisons++;

        if (values[i] == target)
        {
            return i; // Target found
        }
    }

    return -1; // Target not found
}

int main()
{
    int sizes[] = {1000, 10000, 100000, 1000000};

    cout << "Linear Search Performance Analysis\n";
    cout << "==================================\n\n";

    for (int s = 0; s < 4; s++)
    {
        int size = sizes[s];

        // Dynamically allocate array
        int* values = new int[size];

        // Fill array with sequential values
        for (int i = 0; i < size; i++)
        {
            values[i] = i + 1;
        }

        // Target positions
        int targets[4] = {
            values[0],          // First position
            values[size / 2],   // Middle position
            values[size - 1],   // Last position
            -1                  // Absent
        };

        string positions[4] = {
            "First",
            "Middle",
            "Last",
            "Absent"
        };

        cout << "Input Size: " << size << "\n";

        for (int p = 0; p < 4; p++)
        {
            long long totalTime = 0;
            int comparisons = 0;

            cout << "\nTarget Position: " << positions[p] << endl;

            for (int trial = 1; trial <= 5; trial++)
            {
                int currentComparisons;

                auto start = high_resolution_clock::now();

                linearSearch(
                    values,
                    size,
                    targets[p],
                    currentComparisons
                );

                auto stop = high_resolution_clock::now();

                auto duration =
                    duration_cast<nanoseconds>(stop - start);

                totalTime += duration.count();

                comparisons = currentComparisons;

                cout << "Trial " << trial
                     << ": " << duration.count()
                     << " ns" << endl;
            }

            double averageTime =
                static_cast<double>(totalTime) / 5.0;

            cout << "Comparisons: "
                 << comparisons << endl;

            cout << "Average Time: "
                 << averageTime
                 << " ns\n";
        }

        cout << "\n----------------------------------\n";

        delete[] values;
    }

    return 0;
}