/*            
//      Created by ivant.
*/              
#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define MOD 998244353
#define FOR(i, a, b) for(long long i = a; i <= b; i++)
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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<ii> vii;
typedef vector<pll> vpll;

void solve(){

  ll n; cin >> n;
  
  vll par(n+1, 0);
  FOR(i, 2, n) cin >> par[i];

  vll depth(n+1, 0);
  depth[1] = 0;
  ll maxd = 0;
  FOR(i, 2, n){
    depth[i] = depth[par[i]] + 1;
    if(depth[i] > maxd) maxd = depth[i];
  }

  vvll groups(maxd+1);
  FOR(i, 1, n){
    groups[depth[i]].pb(i);
  }

  vll dp(n+1), f(maxd+1);
  dp[1] = 1, f[0] = 1;

  if(maxd >= 1){
    for(auto &i: groups[1]){
      dp[i] = 1;
      f[1] = (f[1] + dp[i]) % MOD;
    }
  }

  FOR(i, 2, maxd){
    for (ll u: groups[i]){
      ll add = f[i-1] - dp[par[u]];
      if(add < 0) add += MOD;
      dp[u] = add % MOD;
      f[i] = (f[i] + dp[u]) % MOD;
    }
  }

  ll res = 0;
  FOR(i, 0, maxd) res = (res + f[i]) % MOD;

  cout << res << "\n";

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