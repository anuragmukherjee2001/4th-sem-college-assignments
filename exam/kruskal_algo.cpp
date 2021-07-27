#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int source;
    int destination;
    int weight;
};

bool Compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

void merge(Edge a[], int l, int mid, int r, int n)
{
    int i = l, j = mid + 1, k = l, t = 1;
    Edge z[r + 1];
    while (i <= mid && j <= r)
    {
        if (a[i].weight >= a[j].weight)
            z[k++] = a[i++];
        else
            z[k++] = a[j++];
    }
    while (i <= mid)
        z[k++] = a[i++];
    while (j <= r)
        z[k++] = a[j++];

    for (int i = l; i <= r; ++i)
        a[i] = z[i];
}
void merge_sort(Edge a[], int l, int r, int n)
{
    int mid;
    static int t = 1;
    if (l < r)
    {
        mid = (l + r) / 2;
        merge_sort(a, l, mid, n);
        merge_sort(a, mid + 1, r, n);
        merge(a, l, mid, r, n);
    }
}

int find(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return find(parent[v], parent);
}

void kruskalAlgo(Edge *input, int n, int E)
{
    sort(input, input + E, Compare);

    Edge *output = new Edge[n - 1];

    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;

    while (count != n - 1)
    {
        Edge current = input[i];

        int sourceParent = find(current.source, parent);
        int destParent = find(current.destination, parent);

        if (sourceParent != destParent)
        {
            output[count] = current;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].destination)
        {
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
}

int main()
{
    int n, E;
    cout << "Enter the number of vertices and Edges";
    cin >> n >> E;
    Edge *input = new Edge[E];

    for (int i = 0; i < E; i++)
    {
        int src, dest, wt;
        cin >> src >> dest >> wt;

        input[i].source = src;
        input[i].destination = dest;
        input[i].weight = wt;
    }

    cout << "The Result is:" << endl;
    kruskalAlgo(input, n, E);
    return 0;
}
