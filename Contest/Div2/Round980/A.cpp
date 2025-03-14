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
    int a, b; cin >> a >> b;
    if(a >= b) cout << a << endl;
    else{
      int aux = abs(a-b);
      a -=aux, b -= 2*aux;
      if(a<0) cout << 0 << endl;
      else cout << a << endl;
    }
  }
  

  return 0;
}