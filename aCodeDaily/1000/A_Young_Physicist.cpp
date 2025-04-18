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

void solve(){

  int n, x = 0, y = 0, z = 0; cin >> n;
  FOR(i, 1, n){
    int xi, yi, zi; cin >> xi >> yi >> zi;
    x += xi, y += yi, z += zi;
  }
  if(!(x || y || z)) cout << "YES\n";
  else cout << "NO\n";
}


int main(){

  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  // int t; cin >> t;
  // while(t--){
    solve();
  // }

  return 0;
}