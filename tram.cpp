#include<bits/stdc++.h>

using namespace std;

int main(){

  int n,a,b,m=0,aux=0;
  cin>>n;
  while(n--&&cin>>a>>b){
    m=m-a+b;
    if(m>aux) aux=m;
  }
  cout<<aux;

  return 0;
}