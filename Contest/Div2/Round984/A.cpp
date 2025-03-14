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
    vector<int> arr(n);
    for(int &v: arr) cin >> v;

    bool isPerfect = true;
    for (int i = 1; i < n; i++)
    {
      int diff = abs(arr[i-1]-arr[i]);
      if(diff == 5 || diff == 7) continue;
      isPerfect = false;
    }
    cout << (isPerfect? "YES":"NO") << endl;
  }
  

  return 0;
}