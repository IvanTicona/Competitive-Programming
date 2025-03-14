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

bool perfect(ll x) {
  ll r = floor(sqrt(x))*1LL;
  return r*r == x;
}

void solve(){

  ll n; cin >> n;
  ll S = n*(n+1)/2;

  if(perfect(S)){
    cout << -1 << "\n";
    return;
  }
  if(n == 1){
    cout << -1 << "\n";
    return;
  }
  if(n == 2){
    cout << "2 1\n";
    return;
  }
  if(n == 3){
    cout << "2 1 3\n";
    return;
  }
  if(n == 4){
    cout << "2 4 1 3\n";
    return;
  }
  if(n == 5){
    cout << "5 1 4 3 2\n";
    return;
  }
  if(n == 6){
    cout << "2 3 6 1 5 4\n";
    return;
  }
  vll res = {2, 3, 6, 7, 1, 5, 4};
  ll sum = 28;
  
  set<ll> R;
  FOR(i, 8, n) R.insert(i);

  while(!R.empty()){
    ll candidate = -1;
    for(auto x: R){
      if(!perfect(sum + x)){
        candidate = x;
        break;
      }
    }
    res.pb(candidate);
    sum += candidate;
    R.erase(candidate);
  }
  for(auto x : res) cout << x << " ";
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