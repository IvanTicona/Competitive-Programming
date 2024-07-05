#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while (t--){
    int x, y;
    cin>>x>>y;
    for (int i = 0; i < 32; i++){
      // cout<<(x&(1<<i))<<"    "<<(y&(1<<i))<<"   "<<(1<<i)<<endl;
      if ((x & (1 << i)) != (y & (1 << i))){
        long long maxi = 1 << i;
        cout<<maxi<<endl;
        break;
      }
    }
  }

  return 0;
}