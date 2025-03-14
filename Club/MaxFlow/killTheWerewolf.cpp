/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct flowEdge
{
  int to, rev, f, cap;
};

vector<vector<flowEdge>> G;

void addEdge(int u, int v, int cap)
{
  flowEdge a = {v, (int)G[v].size(), 0, cap};
  flowEdge b = {u, (int)G[u].size(), 0, 0};
  G[u].push_back(a);
  G[v].push_back(b);
}

int nodes, S, T;
vector<int> work, lvl;
int Q[200010];

bool bfs(){
  int qt = 0;
  Q[qt++] = S;
  lvl.assign(nodes, -1);
  lvl[S] = 0;
  for(int qh = 0; qh < qt; qh++){
    int u = Q[qh];
    for(auto &e: G[u]){
      int v = e.to;
      if(e.cap <= e.f || lvl[v] != -1) continue;
      lvl[v] = lvl[u] + 1;
      Q[qt++] = v;
    }
  }
  return lvl[T] != -1;
}

int dfs(int v, int f){
  if(v == T || f == 0) return f;
  for(int &i = work[v]; i < (int)G[v].size(); i++){
    flowEdge &e = G[v][i];
    int u = e.to;
    if(e.cap <= e.f || lvl[u] != lvl[v] + 1) continue;
    int df = dfs(u, min(f, e.cap - e.f));
    if(df){
      e.f += df;
      G[u][e.rev].f -= df;
      return df;
    }
  }
  return 0;
}

int maxFlow(){
  int res = 0;
  while(bfs()){
    work.assign(nodes, 0);
    while(true){
      int delta = dfs(S, INF);
      if(delta == 0) break;
      res += delta;
    }
  }
  return res;
}


int main(){

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  vector<pair<int,int>> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].first >> v[i].second;
    v[i].first--;
    v[i].second--;
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    nodes = 2*n+2;
    S = 2*n;
    T = 2*n+1;
    G.clear();
    G.resize(nodes);
    int wolfVotes = 0;
    int needed = 0;
    for(int j = 0; j < n; j++){
      if(i==j) continue;
      if(v[j].first == i || v[j].second == i){
        wolfVotes++;
        continue;
      }
      addEdge(j, v[j].first+n, 1);
      addEdge(j, v[j].second+n, 1);
      addEdge(S, j, 1);
      needed++;
    }
    if(wolfVotes < 2){
      ans++;
      continue;
    }
    for(int j = 0; j < n; j++){
      if(i==j) continue;
      int cap = wolfVotes-1;
      if(v[i].first == j || v[i].second == j) cap--;
      addEdge(j+n, T, cap);
    }
    int flow = maxFlow();
    if(flow < needed) ans++;
  }
  cout << ans << endl;

  return 0;
}