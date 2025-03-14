#include <bits/stdc++.h>

using namespace std;

int main(){

  string s, hello = "hello";
  cin>>s;
  int j = 0;
  for (int i = 0; i < s.size(); i++){
    if (s[i] == hello[j]) j++;
  }
  j==5?cout<<"YES":cout<<"NO";

  return 0;
}