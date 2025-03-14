#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi arr(1000000), xl(1000000), xr(1000000), p;

int solve(int n){

  xl[0] = arr[0];
  for(int i = 1; i < n; i++){
    xl[i] = max(xl[i-1], arr[i]);
  }

  xr[n-1] = arr[n-1];
  for(int i = n-2; i >= 0; i--){
    xr[i] = min(xr[i+1], arr[i]);
  }

  for(int i = 0; i < n; i++){
    if(xl[i]<=arr[i] && arr[i]<=xr[i]){
      p.push_back(arr[i]);
    }
  }

  return p.size();
}

int main(){

  int n; cin>>n;

  for(int &v: arr) cin>>v;

  int m = solve(n);
  cout<<m<<" ";

  for (int i = 0; i < min(m, 100); i++) cout<<p[i]<<" ";

  return 0;
}