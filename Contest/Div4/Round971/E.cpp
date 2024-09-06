#include<bits/stdc++.h>

using namespace std;

int main(){

  int t; cin>>t;
  while (t--){
    int n, k;
    cin>>n>>k;
    int r, l;
    int n1=n/2, n2=ceil(double(n)/2);
    r=(n*(n1))/2;
    l=(n*(n2))/2;
    cout<<abs((r*k)-(l*k))<<endl;
  }

  return 0;
}