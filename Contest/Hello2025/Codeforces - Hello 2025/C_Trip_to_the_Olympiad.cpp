/*
Competitive Programming
C. Trip to the Olympiad
Author: Ivan Ticona
Created: 04/01/2025 11:12 AM
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

void solve(){
  ll l, r; cin >> l >> r;

  vll cand;
  for(ll x = l; x <= r && x < l+6; x++){
    cand.pb(x);
  }
  for(ll x = r; x >= l && x > r-6; x--){
    cand.pb(x);
  }
  for(int bit = 0; bit < 31; bit++){
    ll p = 1LL << bit;
    if(p >= l && p <= r){
      cand.pb(p);
    }
  }
  if(l <= 0 && 0 <= r){
    cand.pb(0LL);
  }
  if(l <= 1 && 1 <= r){
    cand.pb(1LL);
  }

  sort(all(cand));
  cand.erase(unique(all(cand)), cand.end());

  if((int)cand.size() < 3){
    cout << l << " " << (l+1) << " " << (l+2) << "\n";
    return;
  }

  int N = (int)cand.size();
  vector pairXOR(N, vll(N));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      pairXOR[i][j] = cand[i] ^ cand[j];
    }
  }
  vvi bestIndices(N);
  for(int i = 0; i < N; i++){
    vector<pair<ll,int>> tmp(N);
    for(int j = 0; j < N; j++){
      tmp[j] = { pairXOR[i][j], j };
    }
    sort(all(tmp), greater<>());

    int limit = min(3, N);
    for(int k = 0; k < limit; k++){
      bestIndices[i].pb(tmp[k].second);
    }
  }
  ll bestVal = -1;
  array<ll, 3> ans = {cand[0], cand[1], cand[2]};

  for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){
      ll baseVal = pairXOR[i][j];

      vi possibleK;
      for(int idx: bestIndices[i]) possibleK.push_back(idx);
      for(int idx: bestIndices[j]) possibleK.push_back(idx);

      for(int k: possibleK){
        if(k == i || k == j) continue;
        ll val = baseVal + pairXOR[i][k] + pairXOR[j][k];
        if(val > bestVal){
          bestVal = val;
          ans = { cand[i], cand[j], cand[k] };
        }
      }
    }
  }
  cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
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