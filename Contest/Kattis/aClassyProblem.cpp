#include<bits/stdc++.h>

using namespace std;

vector<string> sep(string classy){
  vector<string> parts;
  string part = "";
  for (int j = 0; j < classy.size(); j++){
    if (classy[j] == '-'){
      parts.push_back(part);
      part = "";
    }else{
      part += classy[j];
    }
  }
  return parts;
}

int main(){

  freopen("INPUT.txt", "r", stdin);
  freopen("OUTPUT.txt", "w", stdout);

  int t; cin>>t;

  while (t--){
    int n; cin>>n;
    for (int i = 0; i < n; i++){
      string name; cin>>name;
      string classy = "";
      for (int i = 0; ; i++){
        if (name[i] == ':'){
          break;
        }
        classy += name[i];
      }
      vector<string> parts = sep(classy);
    }
  }

  return 0;
}