
#include<bits/stdc++.h>

using namespace std;

int main(){

  int n,x,y,z;
  
  cin>>n>>x>>y>>z;

  if( n < 3 || n < max(max(x,y),z)){
    cout<<"No"<<endl;
  } else{
    if(min(x,y)<= z && z <= max(x,y)){
    cout<<"Yes"<<endl;
    } else{
    cout<<"No"<<endl;
    }
  }

  return 0;
}