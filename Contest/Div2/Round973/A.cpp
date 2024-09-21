#include<bits/stdc++.h>

using namespace std;

int main(){

  int t; cin>>t;
  
  while (t--){
    int n, x, y; cin>>n;cin>>x>>y;
    cout<<(n+min(x,y)-1)/min(x,y)<<endl;
  }

  return 0;
}