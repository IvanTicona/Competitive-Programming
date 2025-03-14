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
    long long n, m, r, c; cin >> n >> m >> r >> c;
    
    unsigned long long res = ((n-r) * m) + ((m-1) * (n-r)) + (m-c);

    cout << res << endl;
  }
  

  return 0;
}