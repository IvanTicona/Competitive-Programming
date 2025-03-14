#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){

  vector<int> ans(1000001, 0);
  ll fac = 1;
  for (int i = 1; i <= 1000000; i++){
    fac *= i;
    while (fac % 10 == 0){
      fac /= 10;
    }
    ans[i] = fac % 10;
    fac %= 1000000;
  }

  ll n;
  while (cin >> n && n != 0){
    cout << ans[n] << endl;
  }

  return 0;
}