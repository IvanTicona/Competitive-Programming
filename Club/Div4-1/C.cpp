#include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while (t--){
    int n;
    cin>>n;
    int moves=0;
    if(n==1) moves=2;
    else if(n%3==0) moves=n/3;
    else moves=n/3+1;
    cout<<moves<<endl;
  }

  return 0;
}