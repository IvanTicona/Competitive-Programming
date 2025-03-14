#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod(ll a, ll mod){
  return ((a%mod)+mod)%mod;
}

ll modPow(ll b, ll p, ll m) {
  if (p == 0) return 1;
  ll ans = modPow(b, p/2, m);
  ans = mod(ans*ans, m);
  if (p&1) ans = mod(ans*b, m);
  return ans;
}

int main(){

  int t;
  cin>>t;
  int MOD = 1000000007;

  while(t--){
    ll d;
    cin>>d;
    ll answer = 8 * modPow(9, d-1, MOD) % MOD;
    cout<<answer<<endl;
  }

  return 0;
}
