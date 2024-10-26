/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  bool cs[3];
  memset(cs,false,sizeof(cs));
  string s; cin >> s;
  for(char &c: s){
    if(c-65 >= 0 && c-65 <= 2){
      cs[c-65] = true;
    }
  }

  if(cs[0] && cs[1] && cs[2]) cout << "Yes" << endl;
  else  cout << "No" << endl;

  return 0;
}