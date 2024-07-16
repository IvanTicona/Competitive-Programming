#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod_pow(ll base, ll exp, ll mod){
  ll res = 1;
  while (exp > 0){
    if (exp % 2 == 1){
      res = (res * base) % mod;
    }
    base = (base * base) % mod;
    exp /= 2;
  }
  return res;
}

int main(){

  int t;
  cin>>t;
  int MOD = 1000000007;

  while(t--){
    ll d;
    cin>>d;
    ll answer = 8 * mod_pow(9, d-1, MOD) % MOD;
    cout<<answer<<endl;
  }

  return 0;
}
