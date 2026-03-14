#include<iostream>
#include<queue>
using namespace std;

int adj[10][10], color[10], n;

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int v = 0; v < n; v++) {
            if(adj[u][v]) {
                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if(color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];

    for(int i = 0; i < n; i++)
        color[i] = -1;

    if(bfs(0))
        cout << "Yes Bipartite";
    else
        cout << "Not Bipartite";

    return 0;
}