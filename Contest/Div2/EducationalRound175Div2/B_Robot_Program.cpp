/*            
//      Created by ivant.
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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pll> vpll;

void solve(){

  ll n, x, k; cin >> n >> x >> k;
  string s; cin >> s;

  vll p(n+1, 0);
  FOR(i, 0, n-1){
    p[i+1] = p[i] + (s[i]=='R' ? 1: -1);
  }

  ll first = -1;
  FOR(i, 1, n){
    if(x+p[i] == 0){
      first = i;
      break;
    }
  }
  if(first == -1 || first > k){
    cout << 0 << "\n";
    return;
  }

  ll res = 1, time = first, t = -1;
  FOR(i, 1, n){
    if(p[i] == 0){
      t = i;
      break;
    }
  }

  if(t == -1){
    cout << res << "\n";
    return;
  }

  res += (k-time) / t;
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