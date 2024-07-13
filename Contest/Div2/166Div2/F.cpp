#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 300005;

vector<int> adj[MAXN];
int depth[MAXN];
int subtree_size[MAXN];
int n;

void dfs(int v, int p, int d) {
    depth[v] = d;
    subtree_size[v] = 1;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
            subtree_size[v] += subtree_size[u];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
        }

        for (int i = 1; i < n; ++i) {
            int v, u;
            cin >> v >> u;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        dfs(1, -1, 0);

        // Gather depths of all nodes except the root
        vector<int> depths;
        for (int i = 2; i <= n; ++i) {
            depths.push_back(depth[i]);
        }
        sort(depths.begin(), depths.end(), greater<int>());

        // Calculate the number of bridges left after adding k edges
        vector<int> result(n - 1);
        for (int k = 1; k < n; ++k) {
            if (k - 1 < depths.size()) {
                result[k - 1] = depths[k - 1];
            } else {
                result[k - 1] = 0;
            }
        }

        for (int i = 0; i < n - 1; ++i) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
