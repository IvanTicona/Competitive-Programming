#include<bits/stdc++.h>

using namespace std;

int main(){

  long long n, k;
  cin>>n>>k;
  long long cant = (n+1)/2;
  if(k<=cant){
    cout<<2*k-1;
  }else{
    cout<<2*(k-cant);
  }

  return 0;
}