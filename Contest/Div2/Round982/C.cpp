/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

bool exists(vector<ll> &arr, ll currentSize, int n){
  bool e = false;
  for(ll i = 1; i <= n; i++){
    if(arr[i] == (currentSize+1-i)){
      e = true;
    }
  }
  return e;
}

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while (t--)
  {
    ll n; cin >> n;
    vector<ll> arr(n+1);
    for(ll i = 1; i <= n; i++) cin >> arr[i];
    ll currentSize = n;

    while(exists(arr, currentSize, n))
    {
      ll mx = 0;
      for(ll i = 1; i <= n; i++){
        if(arr[i] == (currentSize+1-i)){
          mx = max(mx, i);
        }
      }
      currentSize += (mx-1);
    }
    cout << currentSize << endl;
  }
  

  return 0;
}