#include<bits/stdc++.h>

using namespace std;

#define lli long long int

int main(){

  int t;
  cin>>t;
  while (t--){

    lli n, k;
    cin>>n>>k;
    cout<<k+(k-1)/(n-1)<<endl;
  }

  return 0;
}