#include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while (t--){
    string s;
    cin>>s;
    int cero = 0;
    int uno = 0;
    int pieces = 0;
    bool half = false;
    for (int i = 0; i < s.size(); i++){
      if(s[i] == '0') cero++;
      if(s[i] == '1') uno++;
      if(s[i]=='0' && s[i+1]=='1' && !half){
        half = true;
      }else if(s[i]!=s[i+1]){
        pieces++;
      }
    }
    if(cero==s.size()||uno==s.size())cout<<1<<endl;
    else cout<<pieces<<endl;
  }
  return 0;
}