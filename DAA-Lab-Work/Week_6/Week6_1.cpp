#include<iostream>
using namespace std;

int adj[10][10], visited[10], n;

bool dfs(int u, int dest) {
    if(u == dest) return true;

    visited[u] = 1;

    for(int v = 0; v < n; v++) {
        if(adj[u][v] == 1 && !visited[v]) {
            if(dfs(v, dest))
                return true;
        }
    }
    return false;
}

int main() {
    int src, dest;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];

    cout << "Enter source and destination: ";
    cin >> src >> dest;

    if(dfs(src, dest))
        cout << "Yes Path Exists";
    else
        cout << "No Path Exists";

    return 0;
}