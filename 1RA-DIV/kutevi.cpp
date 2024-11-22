#include<bits/stdc++.h>

using namespace std;

int main(){

  int n, k; cin >> n >> k;
  int num = 360;
  for(int i = 0; i < n; i++) {
    int angle; cin >> angle;
    num = __gcd(num, angle);
  }

  for(int i = 0; i < k; i++) {
    int q; cin >> q;
    if(q % num == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  
  return 0;
}