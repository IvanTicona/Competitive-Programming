/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;
    if(n%2==0){
      cout << "Sakurako" << endl;
    }else{
      cout << "Kosuke" << endl;
    }
  }

  return 0;
}