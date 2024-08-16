#include <bits/stdc++.h>

using namespace std;

int main(){
  
  string s;
  cin>>s;
  bool ab=false;
  bool ba=false;

  for (int i = 0; i < s.size() - 1; i++){
    if (!ab && s[i]=='A' && s[i+1]=='B'){
      ab=true;
      i++;
    }else if (ab && s[i]=='B' && s[i+1]=='A'){
      ba=true;
      break;
    }
  }

  if (!ba){
    ab=false;
    for (int i = 0; i < s.size()-1; i++){
      if (!ba && s[i]=='B' && s[i+1]=='A'){
        ba=true;
        i++;
      }else if (ba && s[i]=='A' && s[i+1]=='B'){
        ab=true;
        break;
      }
    }
  }

  if (ab && ba) cout<<"YES";
  else cout<<"NO";

  return 0;
}
