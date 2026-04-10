#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

int parent[20];

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int find(int x)
{
    while (parent[x] != x)
        x = parent[x];

    return x;
}

void Union(int a, int b)
{
    parent[find(a)] = find(b);
}

int main()
{
    int V;

    cin >> V;

    int graph[20][20];

    Edge edges[100];

    int k = 0;

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;

        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] != 0 && i < j)
            {
                edges[k].u = i;
                edges[k].v = j;
                edges[k].w = graph[i][j];
                k++;
            }
        }
    }

    sort(edges, edges + k, cmp);

    int cost = 0;

    for (int i = 0; i < k; i++)
    {
        if (find(edges[i].u) !=
            find(edges[i].v))
        {
            cost += edges[i].w;

            Union(edges[i].u,
                  edges[i].v);
        }
    }

    cout << "Minimum Spanning Weight: "
         << cost;

    return 0;
}