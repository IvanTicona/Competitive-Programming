#include<bits/stdc++.h>

using namespace std;

int main(){

  int n,a=0,d=0;
  string s;
  cin>>n>>s;
  for (int i = 0; i < n; i++){
    s[i] == 'A' ? a++ : d++;
  }
  if(a>d){
    cout<<"Anton";
  }else if(d>a){
    cout<<"Danik";
  }else{
    cout<<"Friendship";
  }

  return 0;
}