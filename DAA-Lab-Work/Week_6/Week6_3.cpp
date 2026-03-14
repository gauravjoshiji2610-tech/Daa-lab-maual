#include<iostream>
using namespace std;

int adj[10][10], visited[10], recStack[10], n;

bool dfs(int u) {
    visited[u] = 1;
    recStack[u] = 1;

    for(int v = 0; v < n; v++) {
        if(adj[u][v]) {
            if(!visited[v] && dfs(v))
                return true;
            else if(recStack[v])
                return true;
        }
    }

    recStack[u] = 0;
    return false;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i)) {
                cout << "Yes Cycle Exists";
                return 0;
            }
        }
    }

    cout << "No Cycle Exists";
    return 0;
}