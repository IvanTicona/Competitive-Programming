#include<bits/stdc++.h>

using namespace std;

int main(){

  int t, c=1;
  cin>>t;
  while (t--){
    int l,w,h;
    cin>>l>>w>>h;
    cout<<"Case "<<c++<<": ";
    if(l<=20 && w<=20 && h<=20) cout<<"good"<<endl;
    else cout<<"bad"<<endl;
  }

  return 0;
}