
#include<bits/stdc++.h>

using namespace std;

int dfs(int node, int end, const vector<vector<int>>& graph) {
  if (node == end) {
    return 1;  // Si alcanzamos el nodo destino, contamos este camino
  }

  int count = 0;
  for (int neighbor : graph[node]) {
    count += dfs(neighbor, end, graph);  // Exploramos vecinos recursivamente
  }

  return count;
}

int count_paths_dfs(const vector<vector<int>>& graph, int start, int end) {
  return dfs(start, end, graph);
}

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, m; cin >> n >> m;  
  vector<vector<int>> graph(n);

  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
  }

  int start = 0;
  int end = 5;

  cout << "Número de caminos de " << start << " a " << end << ": " << count_paths_dfs(graph, start, end) << endl;


  return 0;
}