#include<bits/stdc++.h>

using namespace std;

void solve(){

  int n, k; cin>>n>>k;
  int c=0, g=0;
  while (n--){
    int a; cin>>a;
    if(a>=k) g+=a;
    else if(g>0 && a==0){g--;c++;}
    
  }
  cout<<c<<endl;
}

int main(){

  freopen("input.txt","r", stdin);

  int t; cin>>t;
  while (t--){
    solve();
  }

  return 0;
}