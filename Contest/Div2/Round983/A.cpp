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
    int cntON = 0;
    for(int i = 0; i < 2*n; i++){
      int v; cin >> v;
      if(v == 1) cntON++;
    }
    
    if(cntON % 2 == 0) cout << 0 << " ";
    else cout << 1 << " ";

    if (cntON == n) cout << n << endl;
    else if(cntON == 0) cout << 0 << endl;
    else if(cntON < n) cout << cntON <<endl;
    else cout << n - (cntON - n)  << endl;
  }

  return 0;
}