/*
Competitive Programming
C. Bewitching Stargazer
Author: Ivan Ticona
Created: 28/12/2024 11:16 AM
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
typedef pair<ll, ll> pll;

unordered_map<ll, pll> dp;

pll getVal(ll len, ll k){
  if(len < k) return {0,0};
  auto it = dp.find(len);
  if(it != dp.end()) return it->second;

  if(len % 2 == 0){
    auto [c2, t2] = getVal(len / 2, k);
    ll c = 2 * c2;
    ll t = 2 * t2 + (len / 2) * c2;
    dp[len] = {c, t};
    return {c, t};
  }
  ll mid = (len - 1) / 2;
  auto [c2, t2] = getVal(mid, k);
  ll c = 1 + 2 * c2;
  ll t = mid + 2 * t2 + (mid + 1) * c2;
  dp[len] = {c, t};
  return {c, t};
}

void solve(){
  ll n, k; cin >> n >> k;
  dp.clear();
  pll res = getVal(n, k);
  cout << res.F + res.S << '\n';
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