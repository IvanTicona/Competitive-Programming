#include<bits/stdc++.h>

using namespace std;

int main(){

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n+1);

  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  cout << graph[n].size() << endl;
  for(int neighbor : graph[n]){
    cout << neighbor << " " << n << endl;
  }
  cout << endl;

  return 0;
}