#include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while (t--){

    long long x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    
    long long diffx=abs(x2-x1);
    long long diffy=abs(y2-y1);
    long long res=diffx+diffy;

    if(diffx<diffy) swap(diffx,diffy);

    diffx = max(0LL,diffx-diffy-1);
    res+=(diffx+1)/2*2;

    cout<<res<<endl;
    
  }

  return 0;
}