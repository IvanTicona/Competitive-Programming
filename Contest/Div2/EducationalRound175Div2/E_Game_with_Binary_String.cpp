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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pll> vpll;

void solve(){

  ll n; cin >> n;
  string s; cin >> s;

  ll total = 0;
  FORP(i, 3, n, 2) total += n - i + 1;

  ll zeros = 0, odds = 0;
  FOR(i, 0, n-1){
    if(s[i]=='0'){
      ll j = i;
      while(j < n && s[j]=='0') j++;
      ll L = j - i;
      zeros += L*(L+1)/2 - L;
      if(L >= 3){
        ll cnt = (L + 1) / 2 - 1;
        odds += cnt;
      }
      i = j;
    } else {
      i++;
    }
  }

  ll alt = 0;
  FOR(i, 0, n-1){
    ll j = i;
    while(j < n && (j == i || s[j] != s[j-1])) j++;
    ll L = j - i;
    if(L >= 3 && s[i]=='1'){
      ll cnt = (L + 1) / 2 - 1;
      alt += cnt;
    }
    i = j;
  }

  ll all = total - odds;

  if(all > 0) all -= 2;
  ll win = all / 2;
  ll res = zeros + win;
  
  cout << res << "\n";

}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  // int t; cin >> t;
  // while(t--){
    solve();
  // }

  return 0;
}