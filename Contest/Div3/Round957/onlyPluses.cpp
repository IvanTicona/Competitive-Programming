#include <bits/stdc++.h>

using namespace std;

int main() {

  int t;
  cin>>t;
  while (t--){
    int a, b, c;
    cin>>a>>b>>c;
    int maxi = 0;
    for (int i = 0; i <= 5; ++i) {
      for (int j = 0; j <= 5 - i; ++j) {
        int k = 5-i-j;
        int p = (a + i)*(b + j)*(c + k);
        maxi = max(maxi, p);
      }
    }
    cout<<maxi<<endl;
  }

  return 0;
}