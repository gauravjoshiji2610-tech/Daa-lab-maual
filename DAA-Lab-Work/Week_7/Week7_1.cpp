#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printPath(vector<int>& parent, int j)
{
    if (parent[j] == -1)
    {
        cout << j + 1 << " ";
        return;
    }

    printPath(parent, parent[j]);
    cout << j + 1 << " ";
}

void dijkstra(vector<vector<int>>& graph, int src, int V)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;

        for (int i = 0; i < V; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !visited[v]
                && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nShortest Paths:\n";

    for (int i = 0; i < V; i++)
    {
        cout << i + 1 << " : ";
        printPath(parent, i);
        cout << ": " << dist[i] << endl;
    }
}

int main()
{
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int source;
    cin >> source;

    dijkstra(graph, source - 1, V);

    return 0;
}