#include <bits/stdc++.h>

using namespace std;

int n, m;

long long adj[501][501];
long long oadj[501][501];
bool vis[501];
int path[501];
vector<pair<int, int>> minCutEdges;

bool reachable()
{
  memset(vis, false, sizeof(vis));
  queue<int> Q;
  Q.push(1);
  vis[1] = true;
  while (!Q.empty())
  {
    int u = Q.front();
    Q.pop();
    for (int v = 1; v <= n; v++)
    {
      if (adj[u][v] && !vis[v])
      {
        vis[v] = true;
        path[v] = u;
        Q.push(v);
      }
    }
  }
  return vis[n];
}

int main()
{

  cin >> n >> m;
  memset(adj, 0, sizeof(adj));
  memset(oadj, 0, sizeof(oadj));

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u][v]++, adj[v][u]++;
    oadj[u][v]++, oadj[v][u]++;
  }

  int u, v;
  // edmondskarp
  while (reachable())
  {
    long long flow = 1e18;
    for (v = n; v != 1; v = path[v])
    {
      u = path[v];
      flow = min(flow, adj[u][v]);
    }
    for (v = n; v != 1; v = path[v])
    {
      u = path[v];
      adj[u][v] -= flow;
      adj[v][u] += flow;
    }
  }
  
  reachable();
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (vis[i] && !vis[j] && oadj[i][j])
      {
        minCutEdges.push_back({i, j});
      }
    }
  }
  cout << minCutEdges.size() << endl;
  for (auto &a : minCutEdges)
  {
    cout << a.first << " " << a.second << endl;
  }

  return 0;
}