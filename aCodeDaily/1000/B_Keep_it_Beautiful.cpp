
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

  int q; cin >> q;
  vi a(q); rv(a);
  if(q <= 2 || is_sorted(all(a))){
    string res(q, '1');
    cout << res << "\n";
    return;
  }
  string res = "";
  bool mid = false;
  int first, from;

  FOR(i, 0, q-1) {
    if(i == 0) {
      first =  a[i];
      from = a[i];
      res += "1";
    } else {
      if(mid) {
        if (from <= a[i] && a[i] <= first) {
          from = a[i];
          res += '1';
        } else {
          res += '0';
        }
      } else {
        if(a[i] >= from) {
          from = a[i];
          res += "1";
        } else if(a[i] <= first) {
          mid = true;
          from = a[i];
          res += "1";
        } else {
          res += "0";
        }
      }
    }
  }

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