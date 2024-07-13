#include<bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.length();
  int count = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(s[i] == s[j]){
        count++;
        break;
      }
    }
  }
  if((n-count)%2 == 0){
    cout << "CHAT WITH HER!";
  }else{
    cout << "IGNORE HIM!";
  }
  
  return 0;
}