#include<bits/stdc++.h>

using namespace std;

string ordinals(int n){
  if (n==0) return "{}";
  else{
    string r="{";
    for (int i = 0; i < n; i++){
      if(i!=0) r+=",";
      r+=ordinals(i); 
    }
    r+="}";
    return r;
  }
}

int main(){

  int n;
  cin>>n;
  cout<<ordinals(n)<<endl;

  return 0;
}