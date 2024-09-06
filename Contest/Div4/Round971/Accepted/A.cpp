#include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while (t--){
    int a, b;
    cin>>a>>b;
    int c=20;
    for (int i = 1; i <= 10; i++){
      c=min(c,(i-a)+(b-i));
    }
    cout<<c<<endl;
  }

  return 0;
}