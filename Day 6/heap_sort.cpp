#include <iostream>

using namespace std;

int p = 1;

void printArray(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}

void heapAdjust(int arr[], int i, int n)
{
    int key = arr[i];
    int j = 2 * i;

    while (j <= n)
    {
        if (j < n && arr[j] < arr[j + 1])
        {
            j = j + 1;
        }
        if (arr[j] <= key)
        {
            break;
        }
        arr[j / 2] = arr[j];
        j = j * 2;
    }
    arr[j / 2] = key;
}

void heapify(int arr[], int n)
{

    for (int i = n / 2; i >= 1; i--)
    {
        heapAdjust(arr, i, n);
    }
    // printArray(arr, n);
}

void heapsort(int arr[], int n)
{
    heapify(arr, n);

    for (int i = n; i >= 2; i--)
    {
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        heapAdjust(arr, 1, i - 1);

        cout << "PASS " << p << endl;
        printArray(arr, n);
        p++;
        cout << endl;
    }
}

int main()
{
    int n, arr[100];
    cout << "Enter the size of the array " << endl;
    cin >> n;
    cout << "Enter the array " << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    heapsort(arr, n);
    cout << "The sorted array is" << endl;
    printArray(arr, n);
    cout << endl;
    cout << "The number of passes are " << p;
    return 0;
}