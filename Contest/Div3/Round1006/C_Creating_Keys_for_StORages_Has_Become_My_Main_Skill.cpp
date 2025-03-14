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

ll m0(ll x) {
  FOR(p, 0, 31){
    if((x & (1 << p)) == 0) return (1 << p);
  }
  return (1LL << 31);
}

void solve(){

  ll n, x; cin >> n >> x;
  
  if(n == 1){
    cout << x << "\n";
    return;
  }
  
  ll m = m0(x);
  
  vll key;
  
  if(n >= m) {
    FOR(i, 0, m-1){
      key.pb(i);
    }
    
    ll val = 0;
    for (ll num: key) val |= num;
    
    if (val != x) {
      if (key.size() < n) {
        key.pb(x);
        val |= x;
      } else {
        key.back() = x;
      }
    }
    while (key.size() < n) {
      key.pb(0);
    }
  }
  else {
    FOR(i, 0, n-1) {
      key.pb(i);
    }

    ll val = 0;
    for (ll num: key) val |= num;
    
    if (val != x) {
      key.back() = x;
    }
  }
  
  for (ll num: key) {
    cout << num << " ";
  }
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