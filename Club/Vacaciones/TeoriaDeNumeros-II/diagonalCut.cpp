#include<bits/stdc++.h>

using namespace std;
 
typedef long long ll;

ll cuts(ll m, ll n){
  ll g = gcd(m,n);

  if(g>1) return(g*cuts(m/g,n/g));

  if(m%2==0 || n%2==0) return 0;
  
  return 1;
}

int main(){

  ll m, n;
  cin>>m>>n;
  cout<<cuts(m,n)<<endl;

  return 0;
}