
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
  string s1, s2; cin >> s1 >> s2;
  bool ok = true;
  int cnt1 = 0, cnt2 = 0;

  FOR(i, 0, n-1){
    if(i % 2 == 0 && s1[i] == '1' || i % 2 != 0 && s2[i] == '1') cnt1++;
  }

  if(cnt1 > n/2) ok = false;

  if(!ok) { cout << "NO\n"; return; }

  FOR(i, 0, n-1){
    if(i % 2 == 0 && s2[i] == '1' || i % 2 != 0 && s1[i] == '1') cnt2++;
  }

  if(cnt2 > (n+1)/2) ok = false;

  if(ok) cout << "YES\n";
  else cout << "NO\n";
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