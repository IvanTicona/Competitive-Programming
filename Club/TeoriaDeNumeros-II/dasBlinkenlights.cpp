#include<bits/stdc++.h>

using namespace std;

int main(){

  int p, q, s;
  cin>>p>>q>>s;

  if(p*q/gcd(p,q)<=s) cout<<"yes"<<endl;
  else cout<<"no"<<endl;

  return 0;
}