#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int src;
    cin >> src;
    src--;

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int k = 1; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (graph[i][j] &&
                    dist[i] != INT_MAX &&
                    dist[i] + graph[i][j] < dist[j])
                {
                    dist[j] = dist[i] + graph[i][j];
                }
            }
        }
    }

    cout << "Shortest Distance:\n";

    for (int i = 0; i < V; i++)
        cout << i + 1 << " : " << dist[i] << endl;

    return 0;
}