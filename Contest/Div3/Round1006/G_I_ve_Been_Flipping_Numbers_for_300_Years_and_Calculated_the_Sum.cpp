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
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ll root(ll n, ll r) {
  ll l = 1, h = n;
  while(l < h) {
    ll mid = l + (h - l + 1)/2;
    ll pow = 1;
    FOR(i, 0, r-1) {
      pow *= mid;
      if(pow > n) break;
    }
    if(pow <= n) l = mid;
    else h = mid-1;
  }
  return l;
}

ll rev(ll n, ll p) {
  vll digits;
  ll temp = n;
  while(temp > 0) {
    digits.pb(temp % p);
    temp /= p;
  }
  ll res = 0;
  for (ll d: digits) {
    res = (res*p + d) % MOD;
  }
  return res;
}

ll sum(ll n, ll L, ll R) {
  ll res = 0, p = L;
  while(p <= R) {
    ll q = n / p;
    if(q == 0) {
      break;
    }
    ll r = n / q;
    if(r > R) r = R;
    ll count = r-p+1;
    ll s1 = ((p + r) * count / 2 ) % MOD;
    auto squares = [&](ll x) -> ll {
      ll xx = x;
      return (xx * (xx+1) % MOD * (2*xx+1) % MOD * 166666668LL) % MOD;
    };
    ll s2 = ((squares(r) - (p > 1? squares(p-1) : 0)) % MOD + MOD) % MOD;

    ll seg = ((n * s1) % MOD - (q * ((s2 - count + MOD) % MOD) ) % MOD ) % MOD;
    res = (res + (seg % MOD + MOD) % MOD) % MOD;
    p = r+1;
  }
  return (res + MOD) % MOD;
}

void solve(){

  ll n, k; cin >> n >> k;

  ll ans = 0, L = 1;

  if(n > 1) {
    L = (floor(log2(n))+1)*1LL;
  }
  FOR(l, 2, L){
    ll low = root(n, l)+1;
    ll high = root(n, l-1);
    low = max(low, 2LL);
    if(low > high) continue;
    if(high > k) high = k;
    if(low > high) continue;

    if(l == 2) {
      ans = (ans + sum(n, low, high)) % MOD;
    } else {
      FOR(p, low, high){
        ans = (ans + rev(n, p)) % MOD;
      }
    }
  }

  ll low1 = max(n+1, 2LL);
  if(low1 <= k) {
    ll cnt = (k - low1 + 1) % MOD;
    ans = (ans + (n * cnt) % MOD) % MOD;
  }

  ans = (ans % MOD + MOD) % MOD;
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