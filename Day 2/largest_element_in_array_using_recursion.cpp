#include<iostream>

using namespace std;

int n;

int MaxEle(int a[])
{
    static int i = 0, max = INT_MIN;  
    if(i < n) 
    {
        if(max < a[i])
        max = a[i];

        i++;   
        MaxEle(a);
    }
    return max;
}

int main(){
	int arr[100];
	cout << "Enter the size of the array" << endl;
	cin >> n;
	cout << "Enter the array" << endl;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int max = MaxEle(arr);
	cout << "The maximum number is " << max;
	return 0;
}

