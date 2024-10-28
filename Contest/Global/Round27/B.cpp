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
    string res;
    if(n==1 || n==3){
      cout << -1 << endl;
    }else{
      res.assign(n,'3');
      res[n-1] = '6';
      res[n-2] = '6';
      if(n%2 == 1){
        res[n-4] = '6';
      }
      cout << res << endl;
    }
  }

  return 0;
}