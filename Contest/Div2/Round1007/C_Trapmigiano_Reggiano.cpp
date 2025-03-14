/*            
//      Created by ivant.
*/              
#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define MOD 1000000007
#define FOR(i, a, b) for(long long i = a; i <= b; i++)
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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vll> vvll;
typedef vector<pll> vpll;

void solve(){

  ll n, st, en; cin >> n >> st >> en;
  
  vvll graph(n+1);
  FOR(i, 1, n-1){
    ll u, v; cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  
  vll dist(n+1, INF);
  queue<ll> q;
  dist[en] = 0;
  q.push(en);

  while(!q.empty()){
    ll u = q.front();
    q.pop();
    for(auto v: graph[u]){
      if(dist[v] > dist[u] + 1){
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  
  vll perm;
  FOR(i, 1, n) perm.pb(i);

  sort(all(perm), [&](ll a, ll b) {
    return dist[a] > dist[b];
  });
  
  for(auto v: perm) cout << v << " ";
  cout << "\n";

}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}