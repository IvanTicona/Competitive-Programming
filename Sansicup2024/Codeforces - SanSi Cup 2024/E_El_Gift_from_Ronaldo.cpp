/*
Competitive Programming
E. El Gift from Ronaldo
Author: Ivan Ticona
Created: 31/12/2024 07:02 PM
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

ll gcd(ll a, ll b) {
  while (b != 0) {
    const ll t = b;
    b = a % b;
    a = t;
  }
  return a;
}

ll safe_lcm(const ll a, const ll b, const ll limit) {
  const ll g = gcd(a, b);
  const ll a_div = a / g;

  if (b > limit / a_div) {
    return limit + 1;
  }
  return a_div * b;
}

void solve(){
  ll S, N; int K; cin >> S >> N >> K;

  vll arr(K); rv(arr);
  ll answer = N / S;

  FOR(mask, 1, (1 << K)-1) {
    ll l = S;
    int bitsCount = 0;

    FOR(i, 0, K-1) {
      if(mask & (1 << i)){
        bitsCount++;
        l = safe_lcm(l, arr[i], N);
        if(l > N) break;
      }
    }

    if(l <= N){
      const ll cnt = N / l;
      if(bitsCount % 2 == 1) {
        answer -= cnt;
      } else {
        answer += cnt;
      }
    }
  }

  cout << answer << '\n';
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  // int t; cin >> t;
  // while(t--){
    solve();
  // }

  return 0;
}