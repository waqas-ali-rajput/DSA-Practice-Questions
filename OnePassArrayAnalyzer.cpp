#include <iostream>
using namespace std;

int main()
{
    int n;

    // Validate array size
    cout << "Enter array size: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size. Size must be greater than 0." << endl;
        return 1;
    }

    int arr[n];

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Initialize variables
    long long sum = 0;
    int minVal = arr[0];
    int maxVal = arr[0];

    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;
    int evenCount = 0;
    int oddCount = 0;

    // One main processing loop
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        // Minimum and maximum
        if (arr[i] < minVal)
            minVal = arr[i];

        if (arr[i] > maxVal)
            maxVal = arr[i];

        // Positive, negative, zero count
        if (arr[i] > 0)
            positiveCount++;
        else if (arr[i] < 0)
            negativeCount++;
        else
            zeroCount++;

        // Even and odd count
        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    double average = (double)sum / n;

    // Display results
    cout << "\n----- Results -----" << endl;
    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;
    cout << "Minimum Element = " << minVal << endl;
    cout << "Maximum Element = " << maxVal << endl;
    cout << "Positive Values = " << positiveCount << endl;
    cout << "Negative Values = " << negativeCount << endl;
    cout << "Zero Values = " << zeroCount << endl;
    cout << "Even Values = " << evenCount << endl;
    cout << "Odd Values = " << oddCount << endl;

    return 0;
}