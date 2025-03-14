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
typedef vector<ull> vull;
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

vll a;
vll P;
ull N;
ll odd;

ull f(ull x) {
  if(x <= N) return P[x];
  if(x & 1ULL) return odd;
  else return f(x/2) ^ odd;
}

void solve(){

  ull n, l, r;
  cin >> n >> l >> r;
  N = n;
  a.resize(n+1);
  P.resize(n+1);
  FOR(i, 1, n) cin >> a[i];

  P[0] = 0;
  FOR(i, 1, n) P[i] = P[i-1] ^ a[i];
  
  if(l <= n) {
    cout << a[l] << "\n";
    return;
  }

  ull x = l / 2, m, fm;

  if((n+1) & 1ULL) m = n+1;
  else m = n+2;

  if(m <= n) fm = P[m];
  else {
    ull idx = m/2;
    fm = P[n] ^ P[idx];
    ull fprev = P[n];
    FOR(i, n+1, m) {
      ull pos = i/2;
      ull fi = fprev ^ P[pos];
      fprev = fi;
    }
    fm = fprev;
  }

  odd = fm;
  cout << f(x) << "\n";

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