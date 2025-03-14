#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


ll fact(ll num){
  ll res=1;
  for (ll i = 2; i <= num; i++){
    res*=i;
    if(res>=1e9)
    return 1e10;
  }
  return res;
}

ll getComplexity(ll n, int t){
  ll res;
  if(t==1) res = fact(n);
  else if(t==2) res = pow(2, n);
  else if(t==3) res = pow(n, 4);
  else if(t==4) res = pow(n, 3);
  else if(t==5) res = pow(n, 2);
  else if(t==6) res = ceil(n*log2(n));
  else if(t==7) res = n;

  return res;
}

int main(){

  int m, n, t;
  cin>>m>>n>>t;
  if(getComplexity(n,t)<=m) cout<<"AC"<<endl;
  else cout<<"TLE"<<endl;

  return 0;
}