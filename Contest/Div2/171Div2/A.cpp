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
    int X, Y, K; cin >> X >> Y >> K;

    int p = min(X,Y);

    cout << 0 << " " << 0 << " " << p << " " << p << endl;
    cout << 0 << " " << p << " " << p << " " << 0 << endl;
  }

  return 0;
}