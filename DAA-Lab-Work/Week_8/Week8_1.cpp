#include <iostream>
#include <climits>
using namespace std;

int minKey(int key[], bool mst[], int V)
{
    int min = INT_MAX;
    int index;

    for (int i = 0; i < V; i++)
    {
        if (!mst[i] && key[i] < min)
        {
            min = key[i];
            index = i;
        }
    }

    return index;
}

void prim(int graph[20][20], int V)
{
    int parent[20];
    int key[20];
    bool mst[20];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mst, V);

        mst[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] &&
                !mst[v] &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int weight = 0;

    for (int i = 1; i < V; i++)
        weight += graph[i][parent[i]];

    cout << "Minimum Spanning Weight: "
         << weight;
}

int main()
{
    int V;

    cin >> V;

    int graph[20][20];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    prim(graph, V);

    return 0;
}