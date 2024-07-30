#include<bits/stdc++.h>

using namespace std;

int main(){

  int p;
  cin>>p;
  while (p--){
    int k, n;
    cin>>k>>n;
    int s1,s2,s3;
    s1=n*(n+1)/2;
    s2=n*n;
    s3=n*(n+1);
    cout<<k<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
  }

  return 0;
}