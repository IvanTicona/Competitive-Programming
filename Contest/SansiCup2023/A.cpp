/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>
#define INF 1000000000

using namespace std;


int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;
    vector<int> grafo[n];
    if(n == 1)
    {
      cout << "F" << endl;
      continue;
    }
    for (int i = 0; i < n-1; i++)
    {
      int a, b; cin >> a >> b;
      a--, b--;
      grafo[a].push_back(b);
      grafo[b].push_back(a);
    }

    vector<int> dist(n, INF); dist[0] = 0;
    vector<bool> leaf(n, false);

    queue<int> q; q.push(0);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if(grafo[u].size() == 1 && u != 0){
        leaf[u] = true;
      }
      for (auto &v: grafo[u]) {
        if (dist[v] != INF) continue;
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }
    int win = INF;
    for (int i = 0; i < n; i++)
    {
      if(leaf[i]){
        win = min(win, dist[i]);
      }
    }
    if(win%2 == 0) cout << "O" << endl;
    else cout << "F" << endl;
  }

  return 0;
}