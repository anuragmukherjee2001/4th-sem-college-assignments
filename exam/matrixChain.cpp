// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MAX 10
#define INT_MAX1 999

void printOptimalParens(int s[MAX][MAX], int i, int j)
{

    if (i == j)
    {
        cout << "A" << i;
    }

    else
    {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int matrixChainMul(int p[], int n)
{

    int m[n][n];
    int s[MAX][MAX];

    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {

            int j = i + len - 1;
            m[i][j] = INT_MAX1;

            for (int k = i; k <= j; k++)
            {

                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "The dp matrix is" << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (j < i)
            {
                cout << "INF"
                     << "\t";
            }
            else
            {
                cout << m[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;

    printOptimalParens(s, 1, n - 1);
    cout << endl;

    return m[1][n - 1];
}

int main()
{

    int n;

    cin >> n;

    int p[n];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    cout << "P array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    int min_op = matrixChainMul(p, n);

    cout << "Minimum number of multiplications is " << min_op << endl;

    return 0;
}