#include <iostream>
#include <algorithm>
using namespace std;
 
struct Job
{
    int start, finish, profit;
};
 
bool jobComparataor(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}
 
int latestNonConflict(Job arr[], int i)
{
    for (int j=i-1; j>=0; j--)
    {
        if (arr[j].finish <= arr[i-1].start)
            return j;
    }
    return -1;
}

int findMaxProfitRec(Job arr[], int n)
{
    if (n == 1) return arr[n-1].profit;
 
    int inclProf = arr[n-1].profit;
    int i = latestNonConflict(arr, n);
    if (i != -1)
      inclProf += findMaxProfitRec(arr, i+1);
 
    int exclProf = findMaxProfitRec(arr, n-1);
 
    return max(inclProf,  exclProf);
}
 
int findMaxProfit(Job arr[], int n)
{
    sort(arr, arr+n, jobComparataor);
 
    return findMaxProfitRec(arr, n);
}

int main()
{
    Job arr[100];
    int n;
    cout << "Enter the number"<< endl;
    cin >> n;
    for(int i = 0; i < n; i++){
        
    }
    cout << "The optimal profit is " << findMaxProfit(arr, n);
    return 0;
}