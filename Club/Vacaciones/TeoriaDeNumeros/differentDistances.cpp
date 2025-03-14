#include<bits/stdc++.h>

using namespace std;

int main(){

  double x1,x2,y1,y2,p;
  while(cin>>x1&&x1!=0){
    cin>>y1>>x2>>y2>>p;
    double result, diffx, diffy, root;
    diffx=abs(x1-x2); diffy=abs(y1-y2);
    diffx=pow(diffx,p); diffy=pow(diffy,p);
    root=diffx+diffy;
    result=pow(root,(1.00/p));
    cout<<fixed<<setprecision(10)<<result<<endl;
  }

  return 0;
}