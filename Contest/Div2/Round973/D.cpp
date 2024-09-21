#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){

  ll n; cin>>n;
  vector<ll> arr(n);
  for(ll &v: arr) cin>>v;

  ll min_val = arr[0];
  ll sum = arr[0];
  for(ll i=1; i<n; i++) {
    sum += arr[i];
    ll avg = sum / (i+1);
    min_val = min(min_val, avg);
  }

  ll max_val = arr[n-1];
  sum = arr[n-1];
  for(ll i=n-2; i>=0; i--) {
    sum += arr[i];
    ll avg = (sum + n-i-1) / (n-i);
    max_val = max(max_val, avg);
  }

  cout<<max_val - min_val<<endl;
}

int main(){

  ll t; cin>>t;
  while (t--){
    solve();
  }

  return 0;
}