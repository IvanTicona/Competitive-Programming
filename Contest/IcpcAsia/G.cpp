#include <bits/stdc++.h>

using namespace std;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    string B, C;
    cin >> B >> C;
    
    if(m == 1){
      bool allOnes = true;
      for (char ch : B) {
        if(ch == '0'){
          allOnes = false;
          break;
        }
      }
      if( (C[0] == '1' && allOnes) || (C[0] == '0' && !allOnes) ) cout << "yes" << endl;
      else cout << "no" << endl;
      
      continue;
    }
    
    int pos = 0;
    bool possible = true;
    
    for (int i = 0; i < m - 1; i++){
      if(pos >= n){
        possible = false;
        break;
      }
      char expected = C[i];
      if(expected == '1'){
        if(B[pos] != '1'){
          possible = false;
          break;
        }
        pos++;
      } else {
        if(B[pos] == '0'){
          pos++;
        } else {
          while(pos < n && B[pos] == '1'){
            pos++;
          }
          if(pos >= n){
            possible = false;
            break;
          }
          pos++; 
        }
      }
    }
    
    if(pos >= n){
      possible = false;
    } else {
      char expected = C[m - 1];
      if(expected == '1'){
        for (int i = pos; i < n; i++){
          if(B[i] != '1'){
            possible = false;
            break;
          }
        }
      } else {
        bool found = false;
        for (int i = pos; i < n; i++){
          if(B[i] == '0'){
            found = true;
            break;
          }
        }
        if(!found) possible = false;
      }
    }
    
    cout << (possible ? "yes" : "no") << endl;
  }
  
  return 0;
}
