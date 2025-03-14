/*
Competitive Programming
B. Back to the Fruit Forest
Author: Ivan Ticona
Created: 31/12/2024 07:02 PM
*/
#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define RFOR(i, a, b) for(int i = a; i >= b; i--)
#define FORP(i, a, b, c) for(int i = a; i <= b; i += c)
#define RFORP(i, a, b, c) for(int i = a; i >= b; i -= c)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
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

int n;
vvi tree;
vi f;
ll total_fruits = 0;
ll max_sum = 0;
ll initial_sum = 0;
vll subtree_sum;
vll sum_dist;

ll dfs1(const int u, const int parent) {
  subtree_sum[u] = f[u];
  for(const auto &v: tree[u]){
    if(v != parent){
      initial_sum += static_cast<ll>(f[v]);
      dfs1(v, u);
      subtree_sum[u] += subtree_sum[v];
      sum_dist[1] += sum_dist[v] + subtree_sum[v];
    }
  }
  return subtree_sum[u];
}

void dfs2(const int u, const int parent) {
  for(const auto &v: tree[u]){
    if(v != parent){
      sum_dist[v] = sum_dist[u] - subtree_sum[v] + (total_fruits - subtree_sum[v]);
      max_sum = max(max_sum, sum_dist[v]);
      dfs2(v, u);
    }
  }
}

void solve(){
  int n; cin >> n;
  tree.assign(n+1, vi());

  FOR(i, 1, n-1) {
    int a, b; cin >> a >> b;
    tree[a].pb(b);
    tree[b].pb(a);
  }

  f.assign(n+1, 0);
  for(int i = 1; i <= n; ++i) cin >> f[i];

  subtree_sum.assign(n+1, 0);
  sum_dist.assign(n+1, 0);
  total_fruits = 0;

  for(int i = 1; i <= n; ++i) total_fruits += f[i];

  dfs1(1, -1);
  max_sum = sum_dist[1];

  dfs2(1, -1);

  cout << (max_sum + total_fruits) << '\n';
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  // int t; cin >> t;
  // while(t--){
    solve();
  // }

  return 0;
}