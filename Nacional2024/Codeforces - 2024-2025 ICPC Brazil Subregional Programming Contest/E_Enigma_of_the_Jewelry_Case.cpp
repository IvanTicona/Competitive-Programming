/*
Competitive Programming
E. Enigma of the Jewelry Case
Author: Ivan Ticona
Created: 30/12/2024 06:14 PM
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

void rotateK(vvi& K) {
  vvi AUX(sz(K), vi(sz(K)));
  int h = 0;
  RFOR(j, sz(K) - 1, 0) {
    FOR(i, 0, sz(K) - 1) {
      AUX[h][i] = K[i][j];
    }
    h++;
  }
  FOR(i, 0, sz(K) - 1) FOR(j, 0, sz(K) - 1) K[i][j] = AUX[i][j];
}

bool check(const vvi& K) {
  bool r = true, c = true;
  FOR(j, 0, sz(K) - 2) if (K[0][j] > K[0][j+1]) {r = false; break;}
  FOR(i, 0, sz(K) - 2) if (K[i][0] > K[i+1][0]) {c = false; break;}
  return r && c;
}

void solve(){
  int n; cin >> n;
  vvi K(n, vi(n));
  FOR(i, 0, n-1) FOR(j, 0, n-1) cin >> K[i][j];

  int cnt = 0;
  while (!check(K)) {
    cnt ++;
    rotateK(K);
  }
  cout << cnt << '\n';
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