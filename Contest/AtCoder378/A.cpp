/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int arr[4];
  memset(arr, 0, sizeof(arr));
  for (int i = 0; i < 4; i++)
  {
    int j; cin >> j;
    arr[--j]++;
  }
  int mx = 0;
  for (int i = 0; i < 4; i++)
  {
    mx += arr[i]/2;
  }
  
  cout << mx << endl;

  return 0;
}