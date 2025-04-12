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

  int n; cin >> n;
  vi a(n+1), b(n+1), fa(2*n+1), fb(2*n+1);
  
  FOR (i, 1, n) cin >> a[i];
  FOR (i, 1, n) cin >> b[i];
  
  int p = 1;
  FOR (i, 2, n){
    if (a[i] != a[i-1]){
      fa[a[i-1]] = max(fa[a[i-1]], i-p);
      p = i;
    }
  }
  fa[a[n]] = max(fa[a[n]], n-p+1);

  p = 1;
  FOR (i, 2, n){
    if (b[i] != b[i-1]){
      fb[b[i-1]] = max(fb[b[i-1]], i-p);
      p = i;
    }
  }
  fb[b[n]] = max(fb[b[n]], n-p+1);

  int ans = 0;
  FOR (i, 1, 2*n) ans = max(ans, fa[i]+fb[i]);

  // Buscamos los maximos tamanios de subarrays de 
  // cada numero en cada array, porque podemos forzar el merge

  cout << ans << "\n";
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