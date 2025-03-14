/*
Competitive Programming
C. Suffixes
Author: Ivan Ticona
Created: 30/12/2024 02:19 AM
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
  int n; cin >> n;
  vs dict(n); rv(dict);

  unordered_map<string, vector<pair<string,int>>> sufMap;
  sufMap.reserve(5 * n);
  FOR(i, 0, n-1) {
    const string &w = dict[i];
    const size_t len = w.size();
    FOR(j, 1, len) {
      string sfx = w.substr(len - j, j);
      sufMap[sfx].pb({w, i + 1});
    }
  }

  for (auto &kv : sufMap) {
    auto &arr = kv.second;
    sort(arr.begin(), arr.end(),
         [](auto &a, auto &b){
             return a.first < b.first;
         });
  }

  int q; cin >> q;
  while(q--) {
    string s;
    ll k;
    cin >> s >> k;
    const int lenS = static_cast<int>(s.size());

    bool gotAnswer = false;
    RFOR(sufLen, lenS, 1) {
      string sfx = s.substr(lenS - sufLen, sufLen);

      auto it = sufMap.find(sfx);
      if(it == sufMap.end())
        continue;

      auto &arr = it->second;
      if(static_cast<long long>(arr.size()) < k){
        cout << -1 << "\n";
      } else {
        cout << arr[k-1].second << "\n";
      }
      gotAnswer = true;
      break;
    }

    if(!gotAnswer){
      cout << -1 << "\n";
    }
  }
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