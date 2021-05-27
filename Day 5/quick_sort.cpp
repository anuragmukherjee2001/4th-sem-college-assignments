#include<iostream>
using namespace std;

int count = 0;

void swap(int *x,int *y){

    int temp = *y;
    *y = *x;
    *x = temp;
}

void printArray(int arr[], int low, int high){
    int i = 0;
    for(i = low; i < high; i++){

    cout<<arr[i]<<" ";
    }

    cout<<endl;

}

int partition(int arr[], int low,int high){

    int pivot,i,j;
    i=low;
    pivot=arr[high];

    for(j=low; j <= high - 1; j++){


        if(arr[j]<pivot){
            
            swap(&arr[i],&arr[j]);
            i++;

        }
    }
    swap(&arr[high],&arr[i]);

    cout<<"Pivot ="<<pivot<<endl;
    printArray(arr,low,high+1);

    return i;

    
}
void quickSort(int arr[],int low,int high)  
{  
    if (low < high)  
    {  
        int j = partition(arr, low, high);  
        printArray(arr,low,j);
            printArray(arr,j+1,high+1);
        quickSort(arr,low,j - 1);  
        quickSort(arr, j+1, high);  
    }  
}  

int main(void){
    int n, arr[100];

    cout << "Enter the number of elements of the array " << endl;
    cin >> n;

    cout << "Enter the elements of the array " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "The elements of the array are " << endl;

    printArray(arr,0, n);

    return 0;
}