/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;

set<pll> o;

ll x[] = {2,1,-1,-2,-2,-1,1,2};
ll y[] = {1,2,2,1,-1,-2,-2,-1};

void capture(ll i, ll j){
  o.insert({i,j});
  for (ll h = 0; h < 8; h++)
  {
    ll ni = i + y[h];
    ll nj = j + x[h];
    if(ni > 0 && ni <= N && nj > 0 && nj <= N){
      o.insert({ni,nj});
    }
  }
}

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> N;
  ll M; cin >> M;
  ll total = N*N;

  for (ll h = 0; h < M; h++)
  {
    ll i, j; cin >> i >> j;
    capture(i,j);
  }

  ll cnt = o.size();

  cout << total - cnt << endl;

  return 0;
}