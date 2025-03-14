/*
Competitive Programming
F. Multiplicative Arrays
Author: Ivan Ticona
Created: 19/01/2025 10:38 AM
*/
#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
// #define MOD 1000000007
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

const int MOD = 998244353;
const int MAX_K = 100000;

vector<int> divisors[MAX_K + 1];

void precompute_divisors(int k) {
  for (int i = 1; i <= k; ++i) {
    for (int j = i; j <= k; j += i) {
      divisors[j].push_back(i);
    }
  }
}

void solve(){
  int t;
  cin >> t;

  vector<pair<int, int>> queries(t);
  int max_k = 0;

  for (int i = 0; i < t; ++i) {
    cin >> queries[i].first >> queries[i].second;
    max_k = max(max_k, queries[i].first);
  }

  precompute_divisors(max_k);

  for (auto [k, n] : queries) {
    vector<int> dp(k + 1, 0);
    vector<int> result(k + 1, 0);

    for (int i = 1; i <= k; ++i) {
      dp[i] = 1;
    }

    for (int length = 2; length <= min(n, k); ++length) {
      vector<int> new_dp(k + 1, 0);

      for (int x = 1; x <= k; ++x) {
        for (int d : divisors[x]) {
          new_dp[x] = (new_dp[x] + dp[d]) % MOD;
        }
      }

      dp = new_dp;
    }

    for (int x = 1; x <= k; ++x) {
      result[x] = dp[x];
    }

    for (int x = 1; x <= k; ++x) {
      cout << result[x] << " ";
    }
    cout << "\n";
  }
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