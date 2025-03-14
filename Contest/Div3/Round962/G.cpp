#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> visited(n + 1, false);
        int num_components = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                ++num_components;
            }
        }

        // To connect num_components components, we need num_components - 1 roads
        int result = (num_components == 1) ? (n - 1) : (n - 1 + (num_components - 1));
        cout << result << endl;
    }
    return 0;
}
