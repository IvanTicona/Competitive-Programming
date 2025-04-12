/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
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

int f(int a, int b){
  if(a < b) return -1;
  return a != b;
}

void solve(){

  int a, b, c, d; cin >> a >> b >> c >> d;
  int cnt = 0;
  
  if(f(a, c) + f(b, d) > 0) cnt++;
  if(f(a, d) + f(b, c) > 0) cnt++;
  
  cout << cnt * 2 << "\n";
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