/*
Competitive Programming
B. Outstanding Impressionist
Author: Ivan Ticona
Created: 28/12/2024 10:57 AM
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
  int n; cin >> n;

  vll L(n), R(n);
  int maxVal = 2*n;

  FOR(i, 0, n-1) cin >> L[i] >> R[i];

  static int freq[400001];
  FOR(x, 0, maxVal){
    freq[x] = 0;
  }
  FOR(i, 0, n-1){
    if(L[i] == R[i]){
      freq[L[i]]++;
    }
  }

  static int forcedMask[400001];
  FOR(x, 0, maxVal){
    forcedMask[x] = (freq[x] >= 1 ? 1 : 0);
  }

  static int P[400001];
  P[0] = 0;
  FOR(x, 1, maxVal){
    P[x] = P[x-1] + forcedMask[x];
  }

  string ans(n, '0');

  FOR(i, 0, n-1){
    if(L[i] == R[i]){
      ll x = L[i];
      if(freq[x] == 1){
        ans[i] = '1';
      }
    } else {
      ll left = L[i], right = R[i];
      int occ = P[right] - P[left-1];
      int length = (right - left + 1);
      if(occ < length){
        ans[i] = '1';
      }
    }
  }
  cout << ans << "\n";
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