#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

  ll n,prev,count=0,maxi=0;
  cin>>n>>prev;
  ll b=n-1;
  while (b--){
    ll a;
    cin>>a;
    if(a>=prev) count++;
    else count=0;
    prev=a;
    maxi=max(maxi,count);
  }
  cout<<maxi+1;
  return 0;
}