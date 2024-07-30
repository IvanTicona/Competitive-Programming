#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
vll primes;

void sieve(ll upperbound){
  vector<bool> is_prime(upperbound + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i <= upperbound; ++i){
    if (is_prime[i]){
      for (ll j = i * i; j <= upperbound; j += i){
        is_prime[j] = false;
      }
      primes.push_back(i);
    }
  }
}

ll exponent(ll n, ll p){
  ll exp = 0;
  while (n){
    n /= p;
    exp += n;
  }
  return exp;
}

ll numDiv(ll n, ll k){
  if (k > n)
    return 0;
  if (k == 0 || k == n)
    return 1;

  map<ll, ll> factors;
  for (ll prime : primes){
    if (prime > n)
      break;
    ll exp_n = exponent(n, prime);
    ll exp_k = exponent(k, prime);
    ll exp_nk = exponent(n - k, prime);
    factors[prime] = exp_n - exp_k - exp_nk;
  }

  ll ans = 1;
  for (auto &factor : factors){
    ans *= (factor.second + 1);
  }

  return ans;
}

int main(){

  sieve(431);

  ll n, k;
  while (cin>>n>>k){
    cout<<numDiv(n, k)<<endl;
  }

  return 0;
}
