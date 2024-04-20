#include<bits/stdc++.h>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
vector<int> getPos(string &s) {
  vector<int> positions;
  int n = s.length();
  for (int i = 0; i < n;i++) {
    if(s[i+1]=='B'||(s[i]=='B'&& i==n-1)) continue;
    if (s[i] == 'B') {
      positions.push_back(i);
    }
  }
  return positions;
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
  cout<<s<<endl;
  return 0;
}