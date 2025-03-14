/*
Competitive Programming
K. Karamell
Author: Ivan Ticona
Created: 30/12/2024 09:28 PM
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
#define rall(x) x.rbegin(), x.rend()
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
  vi bag(n); rv(bag);

  ll S = 0;
  for (const auto x: bag) S += x;

  if (S % 2 != 0) {
    cout << -1;
    return;
  }

  const ll T = S / 2;

  vi DP(T + 1, -1);
  DP[0] = -2;

  FOR(i, 0, n-1) {
    const int a = bag[i];
    RFOR(j, T, a) {
      if (DP[j-a] != -1 && DP[j] == -1) {
        DP[j] = i;
      }
    }
  }

  if (DP[T] == -1) {
    cout << -1;
    return;
  }

  vi subsetIndex;
  ll current = T;
  while (current > 0) {
    int idx = DP[current];
    subsetIndex.pb(idx);
    current -= bag[idx];
  }

  vb Alice(n, false);
  for (const auto idx: subsetIndex) {
    Alice[idx] = true;
  }

  vi A, B;
  FOR(i, 0, n-1) {
    if (Alice[i]) A.pb(bag[i]);
    else B.pb(bag[i]);
  }

  sort(all(A));
  sort(rall(B));

  vi order;
  const int sizeA = static_cast<int>(A.size());
  const int sizeB = static_cast<int>(B.size());
  int idxA = 0, idxB = 0;
  while(idxA < sizeA || idxB < sizeB){
    if(idxA < sizeA){
      order.pb(A[idxA++]);
    }
    if(idxB < sizeB){
      order.pb(B[idxB++]);
    }
  }
  ll alice = 0, bob = 0;

  for(const auto x: order){
    if(alice <= bob) alice += x;
    else bob += x;
  }

  if(alice == bob){
    for(int i=0; i<order.size(); ++i){
      if(i > 0) cout << " ";
      cout << order[i];
    }
  }
  else{
    cout << "-1";
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