#include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while (t--){
    int n;
    cin>>n;
    int r=1;
    for (int i = 2; i <= n; i++){
      r*=i;
    }
    cout<<r%10<<endl;
  }
  

  return 0;
}