#include <iostream>
using namespace std;

int max(int a, int b)
{
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    else
        return max(
            val[n - 1] + knapSack(W - wt[n - 1],
                                  wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

int main()
{

    int value[100], weight[100], n;
    cout << "Enter the length";
    cin >> n;
    cout << "Enter the values";
    for(int i = 0; i < n; i++){
        cin >> value[i];
    }
    cout << "Enter the weight";
    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }

    int W = 60;
    cout << knapSack(W, weight, value, n);
    return 0;
}