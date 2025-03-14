#include<bits/stdc++.h>

using namespace std;

void swap(int &c, int &n) {
  int aux = c;
  c = n;
  n = aux;
}
vector<int> getPos(string &s) {
  vector<int> pos;
  int n = s.length();
  for (int i = 0; i < n;i++) {
    if(s[i+1]=='B'||(s[i]=='B'&& i==n-1)) continue;
    if (s[i] == 'B') pos.push_back(i);
  }
  return pos;
}

int main(){

  int n,t;
  string s;
  cin>>n>>t>>s;
  vector<int> pos;
  while(t--){
    pos = getPos(s);
    for (int i = 0; i < pos.size(); i++){
      swap(s[pos[i]],s[pos[i]+1]);
    }
  }
  cout<<s;
  return 0;
}