#include<bits/stdc++.h>

using namespace std;

int main(){
  string s;
  int lower = 0;
  cin>>s;
  for (int i = 0; i < s.size(); i++){
    if(s[i] >= 'a' && s[i] <= 'z'){
      lower++;
    }
  }
  if(lower >= s.size()-lower){
    for (int i = 0; i < s.size(); i++){
      cout<<(char)tolower(s[i]);
    }
  } else {
    for (int i = 0; i < s.size(); i++){
      cout<<(char)toupper(s[i]);
    }
  }
  

  return 0;
}