/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

ll modPow(ll a, ll b, ll mod){
  ll res = 1;
  while(b > 0){
    if(b % 2 == 1) res = res * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return res;
}

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  for (int i = 0; i < t; i++)
  {
    ll n; cin >> n;
  }

  for (int i = 0; i < t; i++)
  {
    ll k; cin >> k;
    cout << modPow(2, k, mod) << endl;
  }

  return 0;
}