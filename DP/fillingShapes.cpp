/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int arr[65];

int countWays(int n){
  if(n == 1) return 0;
  if(n == 2) return 2;
  return 2 * countWays(n - 2);
}

void bottomUp(int n){
  for(int i = 0; i <= n; i++) arr[i] = 0;
  arr[2] = 2;
  for (int i = 4; i <= n; i+=2)
  {
    arr[i] = 2*arr[i-2];
  }
}

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n; cin >> n;

  bottomUp(n);
  // cout << countWays(n) << endl;
  cout << arr[n] << endl;

  return 0;
}