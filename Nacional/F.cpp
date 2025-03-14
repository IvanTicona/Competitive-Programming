#include<bits/stdc++.h>

using namespace std;

int main(){

  int n; cin>>n;
  int num=1, denom=2, aux=0;
  while (n>1){
    aux = num+denom;
    num = denom;
    denom = aux;
    n--;
  }
  cout<<num<<endl;

  return 0;
}