#include <iostream>
#include <fstream>
#include <string>
#include "stack.cpp"
using namespace std;

int v;
int mat[10][10];
int vis[100] = {0};

void dfs(int n)
{
    Stack st;
    st.push(n);
    vis[n] = 1;
    while (!st.isEmpty())
    {
        int u = st.pop();
        cout << u << " ";
        for (int w = 0; w < v; ++w)
        {
            if (mat[u][w] == 1)
            {
                if (vis[w] != 1)
                {
                    vis[w] = 1;
                    st.push(w);
                }
            }
        }
    }
}

int main()
{
    fstream infile;
    infile.open("file.txt", ios::in);

    if (!infile)
    {
        cout << "\nError to open the file\n"
             << endl;
        exit(1);
    }

    infile >> v;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            infile >> mat[i][j];
        }
    }

    int e = 0;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (mat[i][j])
            {
                e++;
            }
        }
    }

    int start;
    cout << "Enter the starting value" << endl;
    cin  >> start;

    cout << "DFS of the Graph is: " << endl;
    dfs(start);
    return 0;
}



                    //     0
                    //  /    \
                    // 1       2
                    // |   \    |    
                    // 3-------4
                    // \       /
                    //     5