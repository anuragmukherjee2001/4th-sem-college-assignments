#include <iostream>
#include <fstream>
#include <string>
#include "queue.cpp"
using namespace std;

int v;
int mat[10][10];
int vis[100] = {0};

void bfs(int n)
{
    queue q;
    vis[n] = 1;
    q.insert(n);
    while (!q.isEmpty())
    {
        int u = q.del();
        cout << u << " ";
        for (int w = 0; w < v; w++)
        {
            if (mat[u][w] == 1)
            {
                if (vis[w] != 1)
                {
                    vis[w] = 1;
                    q.insert(w);
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

    cout << endl;

    int start;
    cout << "Enter the starting value" << endl;
    cin  >> start;

    cout << "BFS of the Graph is: " << endl;
    bfs(start);
    return 0;
}

                //         0
                    //  /    \
                    // 1       2
                    // |   \    |    
                    // 3-------4
                    // \       /
                    //     5