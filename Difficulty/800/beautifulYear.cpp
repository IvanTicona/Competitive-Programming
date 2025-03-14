#include<bits/stdc++.h>

using namespace std;

bool isDistintc(int n){
  string s = to_string(n);
  for(int i=0; i<s.size(); i++){
    for(int j=i+1; j<s.size(); j++){
      if(s[i] == s[j]){
        return false;
      }
    }
  }
  return true;
}

int main(){
  int y;
  cin>>y;
  y++;
  while(!isDistintc(y)){
    y++;
  }
  cout<<y;
  return 0;
}