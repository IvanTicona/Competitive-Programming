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
// #define sz(x) (int)x.size()
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
typedef vector<pll> vpll;

ll triangular(ll m) {
  return m*(m-1)/2;
}

void solve(){

  ll k; cin >> k;

  if(k == 0){
    cout << 0 << "\n";
    return;
  }

  vll groups;
  ll rem = k;
  while(rem > 0){
    ll m = (sqrt(8.0*rem+1) + 1)/2;
    while(triangular(m) > rem) m--;
    if(m < 2) m = 2;
    groups.pb(m);
    rem -= triangular(m);
  }

  ll staffs = 0;
  for (ll sz: groups) staffs += sz;

  vpll points;
  ll x = 0;
  ll sep = 1000;
  FOR(i, 0, groups.size()-1){
    ll sz = groups[i];
    ll y = i * sep;
    FOR(j, 0, sz-1){
      points.pb({x + j, y});
    }
    x += sz + 1;
  }

  cout << staffs << "\n";
  for (auto &p: points) {
    cout << p.F << " " << p.S << "\n";
  }
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