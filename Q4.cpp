#include <iostream>
using namespace std;

int bits(int n)
{
    if (n == 0)
        return 1;

    int count = 0;

    while (n > 0)
    {
        count++;
        n /= 2;
    }

    return count;
}

int setBits(int n)
{
    int count = 0;

    while (n > 0)
    {
        count += n % 2;
        n /= 2;
    }

    return count;
}

void printBinary(int n, int length)
{
    for (int i = length - 1; i >= 0; i--)
        cout << ((n >> i) & 1);
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100], output[100];
    int maxValue = 0;

    cout << "Enter decimal integers: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] > maxValue)
            maxValue = arr[i];
    }

    int maxBits = bits(maxValue);

    cout << "\nBinary Representations:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " = ";
        printBinary(arr[i], maxBits);
        cout << endl;
    }

    for (int b = 0; b < maxBits; b++)
    {
        int zeros = 0;
        int ones = 0;
        int count[2] = {0};

        for (int i = 0; i < n; i++)
        {
            int bit = (arr[i] >> b) & 1;
            count[bit]++;

            if (bit == 0)
                zeros++;
            else
                ones++;
        }

        count[1] += count[0];

        for (int i = n - 1; i >= 0; i--)
        {
            int bit = (arr[i] >> b) & 1;
            output[--count[bit]] = arr[i];
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];

        cout << "\nPass " << b + 1;
        cout << " - Bit Position " << b << endl;

        cout << "Zeros: " << zeros << endl;
        cout << "Ones: " << ones << endl;

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " = ";
            printBinary(arr[i], maxBits);
            cout << endl;
        }
    }

    cout << "\nFinal Sorted Array:\n";

    cout << "Decimal:\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\nBinary:\n";

    for (int i = 0; i < n; i++)
    {
        printBinary(arr[i], maxBits);
        cout << " ";
    }

    int longest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (bits(arr[i]) > bits(longest))
            longest = arr[i];
    }

    cout << "\n\nLongest Binary Representation:\n";
    cout << longest << " = ";
    printBinary(longest, bits(longest));
    cout << "\nLength: " << bits(longest) << " bits\n";

    int target = setBits(maxValue);
    int same = 0;

    cout << "\nLargest Input Value:\n";
    cout << maxValue << " = ";
    printBinary(maxValue, bits(maxValue));

    cout << "\nNumber of set bits: " << target << endl;

    cout << "\nNumbers with the same number of set bits:\n";

    for (int i = 0; i < n; i++)
    {
        if (setBits(arr[i]) == target)
        {
            cout << arr[i] << " ";
            same++;
        }
    }

    cout << "\nCount: " << same << endl;

    return 0;
}