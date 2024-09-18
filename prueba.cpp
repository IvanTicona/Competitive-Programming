#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main(){

  int n; cin>>n;
  vi arr(n), left_max(n), right_min(n), pivots;

  for (int &v: arr) cin>>v;

  left_max[0] = arr[0];
  for (int i = 1; i < n; i++){
    left_max[i] = max(left_max[i - 1], arr[i]);
  }

  right_min[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--){
    right_min[i] = min(right_min[i + 1], arr[i]);
  }

  for (int i = 0; i < n; i++){
    if (left_max[i] <= arr[i] && arr[i] <= right_min[i]){
      pivots.push_back(arr[i]);
    }
  }

  int m = pivots.size();
  cout<<m<<" ";
  for (int i = 0; i < min(m, 100); i++){
    cout<<pivots[i]<<" ";
  }
  cout<<endl;

  return 0;
}
