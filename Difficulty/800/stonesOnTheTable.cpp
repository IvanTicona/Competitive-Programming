#include<bits/stdc++.h>

using namespace std;

int main(){

  int n,c=0;string s;
  cin >> n >> s;
  for (int i = 0; i < s.size(); i++){
    if(s[i] == s[i+1]){
      s.erase(i,1);
      i--;
      c++;
    }
  }
  cout<<c;

  return 0;
}