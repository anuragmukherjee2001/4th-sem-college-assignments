#include <iostream>
#include <fstream>

using namespace std;

int d[100][100], a[100][100], n;

int minimum(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void path()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = minimum(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    fstream infile;
    infile.open("matrix.txt", ios::in);

    if (!infile)
    {
        cout << "\nError to open the file\n"
             << endl;
        exit(1);
    }

    infile >> n;

    cout << "Enter the matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            infile >> a[i][j];
            d[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] < 0)
            {
                cout << "The graph contains negetive edge weight" << endl;
                exit(0);
            }
        }
    }

    cout << "The original matrix is" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    path();

    cout << "The final distance matrix is" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
