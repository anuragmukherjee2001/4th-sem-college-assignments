#include <iostream>
#include <fstream>
using namespace std;

#define V 5
#define INT_MAX1 999

int n;
int mat[V][V];


int minKey(int key[], bool mstSet[])
{

    int min = INT_MAX1;
    int min_index;

    for (int i = 0; i < V; i++)
    {
        if (mstSet[i] == false && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \t Weight" << endl;
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
}

void primMST(int graph[V][V])
{
    int parent[V];

    int key[V];

    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX1;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int i = 0; i < V; i++)
        {

            if (graph[u][i] && mstSet[i] == false && graph[u][i] < key[i])
            {
                parent[i] = u;
                key[i] = graph[u][i];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    fstream infile;
    infile.open("file2.txt", ios::in);

    if (!infile)
    {
        cout << endl
             << "Error to open the file"
             << endl;
        exit(1);
    }

    infile >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            infile >> mat[i][j];
        }
    }

    primMST(mat);

    return 0;
}

// 0 - 1   2
// 1 - 2   3
// 0 - 3   6
// 1 - 4   5