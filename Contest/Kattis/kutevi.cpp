#include<bits/stdc++.h>

using namespace std;

int main(){

  int N, K;
  cin>>N>>K;

  int range = 360;
  while(N--){
    int a; cin>>a;
    range=gcd(range,a);
  }

  while (K--){
    int n; cin>>n;
    cout<<(n%range==0? "YES":"NO")<<endl;    
  }

  return 0;
}