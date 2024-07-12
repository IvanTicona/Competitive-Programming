#include<bits/stdc++.h>

using namespace std;

int fibonacci(int n){
  if(n==0) return 1;
  else if(n==1) return 1;
  else return fibonacci(n-2)+fibonacci(n-1);
}

int main(){

  int sum=0;
  int f=0,i=0;
  while(f<4000000){
    i++;
    f=fibonacci(i);
    if(f%2!=0) continue;
    if(f>4000000) break;
    sum+=f;
  }
  cout<<sum<<endl;

  return 0;
}