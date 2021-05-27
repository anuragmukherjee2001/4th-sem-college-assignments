#include<iostream>

using namespace std;

void maxAndmin(int arr[], int low, int high, int &max, int &min)
{
 	if(low==high)
 	{
 	 	max = arr[low];
 	 	min = arr[low];
 	}
 	else
 	{
  		if(low == high-1)
  		{
   			if(arr[low] <arr[high])
   			{
    			max = arr[high];
    			min = arr[low];
   			}
   		else
   		{
    		max = arr[low];
    		min = arr[high];
   		}
  	}
  		else
  		{
   			int mid = (low+high)/2;
   			maxAndmin(arr, low, mid, max, min);
   			int max1 = max;
            int min1 = min;
   			maxAndmin(arr, mid+1, high, max1, min);
   			if(max <max1)
    			max = max1;
   			if(min > min1)
    			min = min1;
  		}
 	}
}


int main ()
{
 	int n, arr[100];
 	
    cout<<"Enter the limit of the array : " << endl;
 	cin>>n;
 	
 	cout<<"Enter the Array Elements: "<<endl;

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

 	int max = arr[0];
 	int min = arr[0];
 	
    maxAndmin(arr, 0, n-1, max, min);

 	cout<<"The maximum element of the array is: "<<max<<endl;
	cout<<"The minimum element of the array is: "<<min<<endl;
 	
     return 0;
}