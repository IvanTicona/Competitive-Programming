#include<bits/stdc++.h>

using namespace std;

int main(){

  //distancia de Manhattan
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << abs(x1 - x2%3) + abs(y1 - y2%3) << endl;  

  return 0;
}