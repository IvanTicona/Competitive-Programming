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
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      mx = max(mx, arr[i]);
    }
    sort(arr.begin(), arr.end());
    int ans = (mx - arr[0]) * (arr.size()-1);
    cout << ans << endl;
  }
  

  return 0;
}