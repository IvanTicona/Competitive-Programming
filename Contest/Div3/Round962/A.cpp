#include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while (t--){
    int n;
    cin>>n;
    int count=0;
    int legs=n;
    while (legs>0){
      if(legs-4>=0){
        legs-=4;
      }else if(legs-2>=0){
        legs-=2;
      }
      count++;
    }
    cout<<count<<endl;
  }

  return 0;
}