#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll bound = 1e9+7;
ll _sieve_size;
bitset<10000010> bs; // 10^7 is the rough limit
vll primos;

void sieve(ll upperbound) {
  _sieve_size = upperbound+1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    primos.push_back(i);
  }
}

int mod(int a, int m) { return ((a%m)+m) % m; }

int modPow(int b, int p, int m) {
  if (p == 0) return 1;
  int ans = modPow(b, p/2, m);
  ans = mod(ans*ans, m);
  if (p&1) ans = mod(ans*b, m);
  return ans;
}

int main(){

  sieve(1000000);

  int N; cin>>N;
  vll foods(N);
  for(ll &Vi: foods) cin>>Vi;
  

  return 0;
}