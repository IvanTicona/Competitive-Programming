#include<bits/stdc++.h>

using namespace std;

int main(){

  int n,r,petya,vasya,tonya,problems=0;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>petya>>vasya>>tonya;
    r = 0;
    r = petya+vasya+tonya;
    if (r>=2) problems++;
  };
  cout<<problems;

  return 0;
}