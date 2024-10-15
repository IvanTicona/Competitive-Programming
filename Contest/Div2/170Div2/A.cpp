/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int a; cin >> a;
  while (a--)
  {
    string s, t; cin >> s >> t;
    int sec = 0;
    int cnt = 0;
    for (int i = 0; i < max(s.size(), t.size()); i++){
      if(s[i] != t[i]) break; 
      cnt++;
    }
    sec += cnt + (cnt>0);
    sec += s.size() - cnt;
    sec += t.size() - cnt;

    cout << sec << endl;
  }

  return 0;
}