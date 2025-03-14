/*
Competitive Programming
F. Fiesta in the Mountains
Author: Ivan Ticona
Created: 31/12/2024 07:03 PM
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

void solve(){
  int n; cin >> n;
  vi h(n); rv(h);
  vll E(n-1, 0);
  FOR(i, 0, n-2) {
    if(h[i+1] > h[i]) E[i] = 3LL * (h[i+1] - h[i]);
    else if(h[i+1] < h[i]) E[i] = 1LL * (h[i] - h[i + 1]);
    else E[i] = 0;
  }

  vll dp(n+4, INF);
  dp[1] = 0;

  FOR(i, 1, n) {
    if(dp[i] == INF) continue;

    if(i+1 <= n){
      if(dp[i] + E[i-1] < dp[i+1]){
        dp[i+1] = dp[i] + E[i-1];
      }
    }

    if(i+1 < n){
      if(dp[i] + E[i] < dp[i+2]){
        dp[i+2] = dp[i] + E[i];
      }
    }
    else if(i+1 == n){
      if(dp[i] < dp[n]){
        dp[n] = dp[i];
      }
    }

    if(i+2 < n){
      if(dp[i] + E[i+1] < dp[i+3]){
        dp[i+3] = dp[i] + E[i+1];
      }
    }
    else if(i+2 == n){
      if(dp[i] < dp[n]){
        dp[n] = dp[i];
      }
    }
  }
  cout << dp[n] << '\n';
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