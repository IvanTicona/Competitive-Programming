#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  while (n--){
    string s;
    cin >> s;
    bool dif = false;
    for (int i = 0; i < s.size()-1; i++){
      if(s[i]!=s[i+1]){
        dif = true;
        break;
      }
    }
    if(dif){
      char aux = s[0];
      cout<<"YES"<<endl<<s.substr(1)+aux<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}