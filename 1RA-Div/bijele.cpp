#include<bits/stdc++.h>

using namespace std;

int main(){

  int correct[] = {1, 1, 2, 2, 2, 8};
  for (int i = 0; i < 6; i++)
  {
    int v; cin >> v;
    cout << abs(correct[i]-v) * (v > correct[i]? -1 : 1) << " ";
  }

  return 0;
}