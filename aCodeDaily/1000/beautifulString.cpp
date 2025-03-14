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
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<ii> vii;

void solve(){

  string s; cin >> s;
  bool ok = true;
  FOR(i, 1, sz(s)-1) if(s[i] == s[i-1] && s[i] != '?') ok = false;
  if(!ok){
    cout << -1 << '\n';
    return;
  }
  
  FOR(i, 0, sz(s)-1) {
    if(s[i] == '?') {
      char prv = (i > 0)? s[i-1]: 'x';
      char nxt = (i < sz(s)-1)? s[i+1]: 'x';
      set<char> l = {'a', 'b', 'c'};
      if(prv != 'x' && includes(l, prv)){
        l.erase(prv);
      }
      if(nxt != 'x' && nxt != '?'){
        if(includes(l, nxt)){
          l.erase(nxt);
        }
      }
      string r(all(l));
      s[i] = r[0];
    }
  }
  cout << s << '\n';
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}