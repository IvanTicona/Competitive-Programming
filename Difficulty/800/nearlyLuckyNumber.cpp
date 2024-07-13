#include<bits/stdc++.h>

using namespace std;

int main(){

  __int64 n;
  cin>>n;
  string s = to_string(n);
  int lucky = 0;
  for (int i = 0; i < s.size(); i++){
    if(s[i] == '4' || s[i] == '7'){
      lucky++;
    }
  }
  (lucky==4||lucky==7)?cout<<"YES":cout<<"NO";

  return 0;
}