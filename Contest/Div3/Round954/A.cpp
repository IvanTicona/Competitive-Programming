#include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while (t--){
    int x=0, y=0, z=0;
    cin>>x>>y>>z;
    int aux = abs(x-1)+abs(y-1)+abs(z-1);
    for (int i = 2; i <= 10; i++){
      aux = min(aux, abs(x-i)+abs(y-i)+abs(z-i));
    }
    cout<<aux<<endl;
  }

  return 0;
}