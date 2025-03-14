#include<bits/stdc++.h>

using namespace std;

int main(){

  int t, n;
  string pass;
  cin >> t;
  while (t--){
    cin >> n >> pass;
    bool invalid = true;
    if(pass.length() <= 1){
      cout << "YES" << endl;
      continue;
    }
    for (int i = 0; i < n-1; i++){
      if((pass[i]>= 'a' && pass[i] <= 'z')||(pass[i] >= '0' && pass[i] <= '9')){
        if(pass[i] <= pass[i+1]){
          invalid = false;
        }else{
          invalid = true;
          break;
        }
      }else{
        break;
      }
    }
    invalid ? cout << "NO" << endl : cout << "YES" << endl;
  }

  return 0;
}