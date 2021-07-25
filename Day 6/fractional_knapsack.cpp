#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value, weight;
};

bool compare(struct Item a, struct Item b)
{
    float r1 = (float)a.value / a.weight;
    float r2 = (float)b.value / b.weight;
    return r1 > r2;
}

float fractionalKnapsack(struct Item arr[],
                          int N, int size)
{
    sort(arr, arr + size, compare);

    int curWeight = 0;

    float finalvalue = 0.0;

    for (int i = 0; i < size; i++)
    {

        if (curWeight + arr[i].weight <= N)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }

        else
        {
            int remain = N - curWeight;
            finalvalue += arr[i].value * ((float)remain / arr[i].weight);

            break;
        }
    }

    return finalvalue;
}

int main()
{
    int N = 60,n;
    Item arr[100];

    for(int i = 0; i < n; i++){
        cout << "Enter the Value and weight";
        cin >> arr[i].value;
        cin >> arr[i].weight;
    }

    cout << "Enter the size" << endl;
    cin >> n;

    cout << "Maximum profit earned = "
         << fractionalKnapsack(arr, N, n);
    return 0;
}