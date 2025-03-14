/*
Competitive Programming
E1. Another Exercise on Graphs (Easy Version)
Author: Ivan Ticona
Created: 04/01/2025 11:26 AM
*/
#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define EPS 1e-9
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define RFOR(i, a, b) for(int i = a; i >= b; i--)
#define FORP(i, a, b, c) for(int i = a; i <= b; i += c)
#define RFORP(i, a, b, c) for(int i = a; i >= b; i -= c)
#define F first
#define S second
#define all(x) x.begin(), x.end()
// #define sort(x) sort(all(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define rv(x) for(auto &i: x) cin >> i
#define includes(x, y) x.find(y) != x.end()
#define fill(x, y) memset(x, y, sizeof(x))
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<ii> vii;

struct Edge {
  int u, v;
  ll w;
};

void solve(){
  int n, m, q; cin >> n >> m >> q;

  vector<Edge> edges;
  edges.reserve(m);

  for(int i = 0; i < m; i++){
    int u, v;
    ll w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  vll uniqueW;
  uniqueW.reserve(m);
  for(auto &e: edges) uniqueW.push_back(e.w);

  sort(uniqueW.begin(), uniqueW.end());
  uniqueW.erase(unique(uniqueW.begin(), uniqueW.end()), uniqueW.end());
  int m_unique = (int)uniqueW.size();

  vector<vector<pair<int,long long>>> adj(n+1);
  for(auto &ed: edges){
    adj[ed.u].emplace_back(ed.v, ed.w);
    adj[ed.v].emplace_back(ed.u, ed.w);
  }
  static int dist[401][401][401];

  for(int idx = 0; idx < m_unique; idx++){
    for(int s = 1; s <= n; s++){
      for(int v = 1; v <= n; v++){
        dist[idx][s][v] = INF;
      }
    }
  }
  for(int idx = 0; idx < m_unique; idx++){
    long long threshold = uniqueW[idx];

    for(int s = 1; s <= n; s++){
      dist[idx][s][s] = 0;

      deque<int> dq;
      dq.push_back(s);

      while(!dq.empty()){
        int u = dq.front();
        dq.pop_front();
        int curCost = dist[idx][s][u];

        for(auto &edge : adj[u]){
          int v = edge.first;
          ll w = edge.second;
          int c = (w > threshold) ? 1 : 0;
          int newCost = curCost + c;
          if(newCost < dist[idx][s][v]){
            dist[idx][s][v] = newCost;
            if(c == 0) dq.push_front(v);
            else dq.push_back(v);
          }
        }
      }
    }
  }
  while(q--){
    int a, b, k; cin >> a >> b >> k;

    int l = 0, r = m_unique - 1;
    ll ans = -1;

    while(l <= r){
      int mid = (l + r) / 2;
      int val = dist[mid][a][b];
      if(val <= k - 1){
        ans = uniqueW[mid];
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    cout << ans << ' ';
  }
  cout << '\n';
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}