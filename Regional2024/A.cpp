/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  string s; cin >> s;
  set<char> l;
  for(char &c: s) l.insert(c);

  cout << s.size() - l.size() << endl;

  return 0;
}