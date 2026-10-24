#include <iostream>
using namespace std;

int digitSum(int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int arr[100], output[100];

    cout << "Enter last four digits of IDs: ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int exp = 1;

    for (int pass = 1; pass <= 4; pass++)
    {
        int count[10] = {0};

        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            int digit = (arr[i] / exp) % 10;
            output[--count[digit]] = arr[i];
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];

        int even = 0;

        for (int i = 0; i < n; i++)
        {
            int digit = (arr[i] / exp) % 10;

            if (digit % 2 == 0)
                even++;
        }

        cout << "\nPass " << pass << ": ";

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << "\nEven digits: " << even << endl;

        exp *= 10;
    }

    cout << "\nDuplicate IDs:\n";

    for (int i = 0; i < n; i++)
    {
        if (i == 0 || arr[i] != arr[i - 1])
        {
            int frequency = 1;

            while (i + frequency < n &&
                   arr[i] == arr[i + frequency])
                frequency++;

            if (frequency > 1)
                cout << arr[i] << " Frequency: "
                     << frequency << endl;
        }
    }

    int highest = -1;
    int bestID = arr[0];

    cout << "\nDigit Sums:\n";

    for (int i = 0; i < n; i++)
    {
        int sum = digitSum(arr[i]);

        cout << arr[i] << ": " << sum << endl;

        if (sum > highest)
        {
            highest = sum;
            bestID = arr[i];
        }
    }

    cout << "\nHighest Digit Sum ID: " << bestID;
    cout << "\nDigit Sum: " << highest << endl;

    int longest = 0;
    int current = 0;
    int start = 0;
    int bestStart = 0;

    for (int i = 0; i < n; i++)
    {
        if (digitSum(arr[i]) % 2 == 0)
        {
            if (current == 0)
                start = i;

            current++;

            if (current > longest)
            {
                longest = current;
                bestStart = start;
            }
        }
        else
        {
            current = 0;
        }
    }

    cout << "\nLongest Sequence with Even Digit Sums:\n";

    for (int i = bestStart; i < bestStart + longest; i++)
        cout << arr[i] << " ";

    cout << "\nLength: " << longest << endl;

    return 0;
}