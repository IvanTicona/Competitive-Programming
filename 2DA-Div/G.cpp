#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int dp[100000000];
// vector<ll> dp(1000000001, -1);
ll coins[] = { 1, 3, 6, 10, 15};

ll f(ll x){
  if(x==0) return 0;
  if(dp[x]==-1){
    ll minCoins = 100000000;
    for (int i = 0; i < 5; i++){
      if(x>=coins[i]){
        ll sol = f(x-coins[i])+1;
        minCoins = min(sol, minCoins);
      }
    }
   dp[x] = minCoins;
  }
  return dp[x];
}

int main() {

  int t; cin>>t;
  while(t--){
  memset(dp, -1, sizeof(dp));
  ll n; 
  cin>>n;
  cout<<f(n);
  }
}