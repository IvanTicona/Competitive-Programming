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

pll find_min_second_min(vector<ll> a) {
  ll min1 = a[0];
  ll min2 = a[1];
  if (min1 > min2) swap(min1, min2);
  for (size_t i = 2; i < a.size(); i++) {
    if (a[i] < min1) {
      min2 = min1;
      min1 = a[i];
    } else if (a[i] < min2) {
      min2 = a[i];
    }
  }
  return {min1, min2};
}

void solve(){

  int n;
  cin >> n;
  ll sum_s = 0;
  ll min_m = 1e18;
  ll min_s = 1e18;
  for (int i = 0; i < n; i++) {
    int m; cin >> m;
    vll a(m);
    for (int j = 0; j < m; j++) cin >> a[j];
    auto [m_i, s_i] = find_min_second_min(a);
    sum_s += s_i;
    min_m = min(min_m, m_i);
    min_s = min(min_s, s_i);
  }
  ll beauty = sum_s - min_s + min_m;
  cout << beauty << "\n";
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