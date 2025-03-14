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
    int r = 0;
    if(arr[2] > arr[1] && arr[1] > arr[0]) r++;
    for (int i = 1; i < n-1; i++)
    {
      if(arr[i-1] == arr[i+1]) continue;
      if(arr[i-1] < arr[i+1]) r++;
    }
    cout << r << endl;
  }

  return 0;
}