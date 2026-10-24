#include <iostream>
using namespace std;

int quickCount = 0;
int mergeCount = 0;

void printArray(int arr[], int l, int r)
{
    for (int i = l; i <= r; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    cout << "Pivot: " << pivot << endl;

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
    int p = i + 1;

    if (p - 1 >= low)
    {
        cout << "Left: ";
        printArray(arr, low, p - 1);
        quickCount++;
    }

    if (p + 1 <= high)
    {
        cout << "Right: ";
        printArray(arr, p + 1, high);
        quickCount++;
    }

    return p;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
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

    cout << "Merged: ";
    printArray(arr, l, r);
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        cout << "Split: ";
        printArray(arr, l, m);
        mergeCount++;

        cout << "Split: ";
        printArray(arr, m + 1, r);
        mergeCount++;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[100], b[100];

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    cout << "\nQuick Sort\n";
    quickSort(a, 0, n - 1);

    cout << "Sorted Array: ";
    printArray(a, 0, n - 1);
    cout << "Total Subarrays: " << quickCount << endl;

    cout << "\nMerge Sort\n";
    mergeSort(b, 0, n - 1);

    cout << "Sorted Array: ";
    printArray(b, 0, n - 1);
    cout << "Total Subarrays: " << mergeCount << endl;

    return 0;
}