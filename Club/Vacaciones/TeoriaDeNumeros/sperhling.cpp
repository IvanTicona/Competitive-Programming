#include<bits/stdc++.h>

using namespace std;

int main(){

  string s1, s2;
  cin>>s1>>s2;
  for (int i=0;i<max(s2.size(),s1.size());i++){
    if(s1[i]!=s2[i]){
      cout<<(s1.size()-i+s2.size()-i)<<endl;
      return 0;
    }
  }
  cout<<0<<endl;

  return 0;
}