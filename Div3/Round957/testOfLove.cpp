#include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while (t--){
    int n, jump, swim;
    cin>>n>>jump>>swim;
    string a;
    cin>>a;
    for (int i = -1; i < n+1; i++){
      i+=jump;
      if(a[i]=='C') {cout<<"NO"<<endl;break;}
      
    }
  }
  

  return 0;
}