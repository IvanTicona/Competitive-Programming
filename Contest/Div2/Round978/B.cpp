
#include<bits/stdc++.h>

using namespace std;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while(t--){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    int totalCars = 0;
    for(int &ai: a) {
      cin >> ai;
      totalCars += ai;
    }
    int ans = (totalCars + x - 1) / x;
    int mx = *max_element(a.begin(), a.end());
    ans = max(ans, mx);
    cout << ans << endl;
  }

  return 0;
}