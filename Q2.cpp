#include <iostream>
using namespace std;

int levelCount[100];

void printArray(int arr[], int l, int r)
{
    for (int i = l; i <= r; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void merge(int arr[], int l, int m, int r)
{
    int L[100], R[100];

    int n1 = m - l + 1;
    int n2 = r - m;

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void hybridSort(int arr[], int l, int r, int level)
{
    if (l >= r)
        return;

    cout << "\nLevel " << level << endl;

    if (level % 2 == 1)
    {
        cout << "Technique: Quick Sort\n";

        int p = partition(arr, l, r);

        cout << "Pivot: " << arr[p] << endl;

        if (p > l)
        {
            cout << "Left: ";
            printArray(arr, l, p - 1);
            levelCount[level]++;
        }

        if (p < r)
        {
            cout << "Right: ";
            printArray(arr, p + 1, r);
            levelCount[level]++;
        }

        hybridSort(arr, l, p - 1, level + 1);
        hybridSort(arr, p + 1, r, level + 1);
    }
    else
    {
        cout << "Technique: Merge Sort Division\n";

        int m = (l + r) / 2;

        cout << "Left: ";
        printArray(arr, l, m);
        levelCount[level]++;

        cout << "Right: ";
        printArray(arr, m + 1, r);
        levelCount[level]++;

        hybridSort(arr, l, m, level + 1);
        hybridSort(arr, m + 1, r, level + 1);

        merge(arr, l, m, r);
    }

    cout << "Subarrays generated at level " << level
         << ": " << levelCount[level] << endl;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    hybridSort(arr, 0, n - 1, 1);

    cout << "\nFinal Sorted Array: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}