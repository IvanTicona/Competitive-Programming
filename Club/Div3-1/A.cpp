#include<bits/stdc++.h>

using namespace std;

#define lli long long int

int main(){

  int t;
  cin>>t;
  while (t--){

    lli n, k;
    cin>>n>>k;
    lli r = k/(n-1);
    lli d = k%(n-1);
    lli kth = d + r*n;
    if(d == 0) kth--;
    cout<<kth<<endl;

  }

  return 0;
}