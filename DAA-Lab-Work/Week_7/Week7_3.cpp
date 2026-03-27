#include <iostream>
#include <climits>
using namespace std;

int shortest(int graph[20][20],
             int u, int v,
             int k, int V)
{
    if (k == 0 && u == v)
        return 0;

    if (k == 1 && graph[u][v])
        return graph[u][v];

    if (k <= 0)
        return INT_MAX;

    int res = INT_MAX;

    for (int i = 0; i < V; i++)
    {
        if (graph[u][i])
        {
            int temp =
            shortest(graph, i, v, k - 1, V);

            if (temp != INT_MAX)
                res = min(res,
                graph[u][i] + temp);
        }
    }

    return res;
}

int main()
{
    int V;
    cin >> V;

    int graph[20][20];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int src, dest, k;

    cin >> src >> dest;
    cin >> k;

    int ans =
    shortest(graph,
             src - 1,
             dest - 1,
             k,
             V);

    if (ans == INT_MAX)
        cout << "No path";

    else
        cout << "Weight of shortest path = "
             << ans;

    return 0;
}