/*
Competitive Programming
E. Building Pigeon Houses
Author: Ivan Ticona
Created: 30/12/2024 02:09 AM
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
  int n, k; cin >> n >> k;
  vll p(n);
  ll sumP = 0;
  for(int i=0; i<n; i++){
    cin >> p[i];
    sumP += p[i];
  }

  if(k > n){
    cout << 0 << '\n';
    return;
  }

  ll lo = 0;
  ll hi = sumP / k;

  auto can = [&](ll x){
    ll s = 0;
    for(int i=0; i<n; i++){
      s += min(p[i], x);
      if(s >= k*x)
        break;
    }
    return (s >= k*x);
  };

  ll ans = 0;
  while(lo <= hi){
    ll mid = (lo + hi) >> 1;
    if(can(mid)){
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  cout << ans << '\n';
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