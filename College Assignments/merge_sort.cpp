#include <iostream>
using namespace std;

// int count = 0;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    int Z[100];

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            Z[k++] = arr[i++];
            
        }
        else {
            Z[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        Z[k++] = arr[i++];
    }

    while (j <= right) {
        Z[k++] = arr[j++];
    }

    for (int i = left; i <= right; i++)
    {
        arr[i] = Z[i];
    }
}

void mergeSort(int arr[],int left,int right){

    if(left < right){

        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}



int main(){

    int n, arr[100];

    cout << "Enter the number of elements of the array " << endl;
    cin >> n;

    cout << "Enter the elements of the array " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "The elements of the array are " << endl;

    printArray(arr, n);

    cout << endl;

    // cout << "The number of comparisons are " << count;

    return 0;
}