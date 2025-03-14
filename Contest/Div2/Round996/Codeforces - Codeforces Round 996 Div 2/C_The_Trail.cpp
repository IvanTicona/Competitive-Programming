/*
Competitive Programming
C. The Trail
Author: Ivan Ticona
Created: 12/01/2025 06:48 PM
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
  int n, m; cin >> n >> m;
  string s; cin >> s;
  vector a(n, vll(m));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }

  vii path;
  path.reserve(n + m - 1);
  {
    int r = 0, c = 0;
    path.emplace_back(r, c);
    for(char move : s){
      if(move == 'R') c++;
      else            r++;
      path.emplace_back(r, c);
    }
  }
  vector inPath(n, vector(m, false));
  for(auto &pcell : path){
    inPath[pcell.first][pcell.second] = true;
  }
  vll rowSum(n, 0LL), colSum(m, 0LL);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!inPath[i][j]) {
        rowSum[i] += a[i][j];
        colSum[j] += a[i][j];
      }
    }
  }
  vll rowNeed(n), colNeed(m);
  for(int i = 0; i < n; i++){
    rowNeed[i] = -rowSum[i];
  }
  for(int j = 0; j < m; j++){
    colNeed[j] = -colSum[j];
  }
  vector<vll> b = a;
  int totalCells = n + m - 1;

  for(int i = 0; i < totalCells; i++){
    auto [r, c] = path[i];

    if(i < s.size()){
      if(s[i] == 'R'){
        long long val = colNeed[c];
        b[r][c] = val;
        rowNeed[r] -= val;
        colNeed[c] -= val;
      } else {
        long long val = rowNeed[r];
        b[r][c] = val;
        rowNeed[r] -= val;
        colNeed[c] -= val;
      }
    }
    else {
      long long val = rowNeed[r];
      b[r][c] = val;
      rowNeed[r] -= val;
      colNeed[c] -= val;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << b[i][j] << (j+1 < m ? ' ' : '\n');
    }
  }
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