/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n, k; cin >> k >> n;

  int mn = (n + 2)/3, mx = (n + 1)/2;
  
  string result = "";
  if( mn <= k &&  k <= mx){
    if((2 * k) <= n){
      int rest = n - (2 * k);
      for (int i = 0; i < k; i++)
      {
        result += "-X";
        if(rest > 0){
          result += '-';
          rest--;
        }
      }
    }else{
      for (int i = 1; i < k; i++)
      {
        result += "X-";
      }
      result += 'X';
    }
    cout << result << endl;
  }else{
    cout << "*" << endl;
  }

  return 0;
}