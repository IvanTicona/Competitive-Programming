#include<bits/stdc++.h>

using namespace std;

#define MAXN 100100
#define MAXV 1000100
#define lli long long int
#define MOD 1000000007

int n;
int counter[MAXV];
int pow2[MAXN];

bool isPrime[MAXV];
int factor[MAXV];

vector<int> lista, answer;

void generateMultiples(int pos, int mult){
  if(pos == lista.size()){
    answer.push_back(mult);
    return;
  }
  generateMultiples(pos+1, mult);
  generateMultiples(pos+1, mult * (-lista[pos]));
}

void generate_prime_numbers(int k){

  set<int> primes;
  while (k>1){
    primes.insert(factor[k]);
    k/=factor[k];
  }
  lista.clear();
  for(auto x: primes){
    lista.push_back(x);
  }
  answer.clear();
  generateMultiples(0, 1);
}

int main(){

  isPrime[1] = false;
  for(int i = 1; i < MAXV; i++) isPrime[i] = true;
  for (int i = 2; i < MAXV; i++){
    if(isPrime[i]){
      factor[i]=i;
      for (lli j = 1LL*i*i; j < MAXV; j+=i){
        factor[j]=i;
        isPrime[j]=false;
      }
    }
  }

  for (int i = 0; i < MAXV; i++){
    counter[i]=0;
  }

  cin>>n;
  int k;
  for (int i = 0; i < n; i++){
    cin>>k;
    generate_prime_numbers(k);
    for(auto x: answer){
      counter[abs(x)]++;
    }
  }

  pow2[0]=1;
  for (int i = 1; i <= n; i++){
    pow2[i]=(2*pow2[i-1]) % MOD;
  }

  int q;
  cin>>q;
  for (int i = 0; i < q; i++){
    cin>>k;
    generate_prime_numbers(k);
    int sum=0;
    for(auto x: answer){
      sum += counter[abs(x)]*(x<0? -1: 1);
    }
    cout<<pow2[sum]<<endl;
  }

  return 0;
}