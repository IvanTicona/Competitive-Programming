/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define RFOR(i, a, b) for(int i = a; i >= b; i--)
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define sz(x) (int)x.size()
#define pb push_back 

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<ii> vii;

void solve(){

  int n; cin >> n;
  string s; cin >> s;
  
  set<char> dis;
  vi m(n, 0);
  int mx = 0;
  
  RFOR(i, n-1, 0){
    dis.insert(s[i]);
    m[i] = dis.size();
  }
  
  dis.clear();
  
  FOR(i, 0, n-2){
    dis.insert(s[i]);
    int fa = dis.size();
    int fb = m[i+1];
    mx = max(mx, fa+fb);
  }
  
  cout << mx << "\n";
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