#include<bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin>>n;
  int firstRing;
  cin>>firstRing;
  for (int i = 1; i < n; i++){
    int A=firstRing, B;
    cin>>B;
    int mcd = gcd(firstRing,B);
    A /= mcd;
    B /= mcd;
    cout<<A<<"/"<<B<<endl;
  }

  return 0;
}