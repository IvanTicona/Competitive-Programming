#include<bits/stdc++.h>

using namespace std;

int main(){
  
  string s,t,ans="YES";
  cin>>s>>t;
  for (int i = 0, j = s.size()-1; i < s.size(); i++,j--){
    if(s[i] != t[j]) ans = "NO";
  }
  cout<<ans;

  return 0;
}