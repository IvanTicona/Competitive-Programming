#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sumDiv(int n){
  ll sum = 0;
  for (ll i = 1; i <= sqrt(n); i++){
    if(n%i == 0){
      sum+=i;
      if(i != n/i){
        sum+=n/i;
      }
    }
  }
  return sum-n;
}

int main(){

  ll n;
  while (cin>>n){
    ll perfect=sumDiv(n);
    if(n==perfect) cout<<n<<" perfect"<<endl;
    else if(n-2<=perfect&&perfect<=n+2) cout<<n<<" almost perfect"<<endl;
    else cout<<n<<" not perfect"<<endl;
  }

  return 0;
}