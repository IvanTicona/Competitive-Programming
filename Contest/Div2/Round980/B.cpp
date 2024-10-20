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
    int n, k, j = 0; cin >> n >> k;
    vector<int> arr(n);
    int sum = 0;
    int press = 0;
    for(int &num: arr) cin >> num;
    sort(arr.begin(), arr.end());
    while(true){
      int mn = arr[j];

      if( sum + (mn * (n-j)) > k) break;

      press += mn * (n - j);
      press++;
      sum += mn * (n - j);
      for (int i = j; i < n; i++)
      {
        arr[i] -= (mn);
        if(arr[i] <= 0) j++;
      }
    }
    if(sum < k){
      press += (k-sum);
    }
    cout << press << endl;
  }
  

  return 0;
}