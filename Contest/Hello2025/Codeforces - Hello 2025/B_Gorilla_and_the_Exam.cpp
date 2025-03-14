/*
Competitive Programming
B. Gorilla and the Exam
Author: Ivan Ticona
Created: 04/01/2025 10:58 AM
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
// #define sort(x) sort(all(x))
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
  ll n, k; cin >> n >> k;
  vll a(n); rv(a);
  sort(all(a));
  vll freq;
  ll curr = a[0];
  ll cnt = 1;
  FOR(i, 1, n-1) {
    if (a[i] == curr) cnt++;
    else {
      freq.pb(cnt);
      curr = a[i];
      cnt = 1;
    }
  }
  freq.pb(cnt);
  sort(all(freq), greater<ll>());

  ll target = n - k;
  if (target <= 0) {
    cout << "1\n";
    return;
  }
  ll sum = 0;
  ll t_min = 0;
  for (auto &f: freq) {
    sum += f;
    t_min++;
    if (sum >= target) {
      break;
    }
  }
  cout << t_min << '\n';
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}