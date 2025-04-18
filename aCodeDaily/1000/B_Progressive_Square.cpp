/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define MOD 1000000007
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
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

void generateSquare(ll n, ll a11, ll c, ll d, map<ll, ll> &elemnts){
  ll base = a11;
  FOR(i, 0, n - 1){
    FOR(j, 0, n - 1){
      elemnts[base + d * j]++;
    }
    base += c;
  }
}

void solve(){

  int n, c, d; cin >> n >> c >> d;
  map<ll, ll> elemnts;
  map<ll, ll> givenNumbers;
  int a11 = INF;

  FOR(i, 1, n*n){
    int v; cin >> v;
    a11 = min(a11, v);
    givenNumbers[v]++;
  }
  generateSquare(n, a11, c, d, elemnts);
  
  if(elemnts == givenNumbers) cout << "YES" << endl;
  else cout << "NO" << endl;
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