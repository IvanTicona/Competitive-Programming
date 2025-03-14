/*
Competitive Programming
L. Lecographically Maximum
Author: Ivan Ticona
Created: 30/12/2024 06:17 PM
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
  vi nums(n); rv(nums);
  vi res(n, 0);

  FOR(bit, 0, 31) {
    int cnt = 0;
    for(const int &v: nums) {
      if (v & 1<<bit) cnt++;
    }
    int index = 0;
    while (cnt > 0) {
      res[index++] |= 1<<bit;
      cnt--;
    }
  }
  for (const int &v: res) cout << v << " ";
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