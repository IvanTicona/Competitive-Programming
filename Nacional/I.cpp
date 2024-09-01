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

set<ll> primeFactors(ll N) { // pre-condition, N >= 1
  set<ll> factors;
  for (int i = 0; (i < (int)primos.size()) && (primos[i]*primos[i] <= N); ++i)
    while (N%primos[i] == 0) {
    N /= primos[i];
    factors.insert(primos[i]);
  }
  if (N != 1) factors.insert(N);
  return factors;
}

ll Pow(ll b, ll e){
  ll r=1;
  while(e--){
    r*=b;
    r%=bound;
  }
  return r%bound;
}

int main(){

  sieve(1000000);

  int N; cin>>N;
  vll foods(N);
  for(ll &Vi: foods) cin>>Vi;

  int Q; cin>>Q;
  while (Q--){
    ll allergies=0;
    int Xi; cin>>Xi;
    set<ll> factores = primeFactors(Xi);
    for(ll Vi: foods){
      for(ll prime: factores){
        if(Vi%prime==0){
          allergies++;
          break;
        }
      }
    }
    cout<<Pow(2,N-allergies)<<endl;
  }

  return 0;
}