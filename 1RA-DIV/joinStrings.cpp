#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &v, vector<string> &s, int idx) {
  cout<<s[idx];
  for(int i: v[idx]) {
    dfs(v, s, i);
  }
}

int main() {

  //FAST I/O
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int n;
  cin>>n;
  vector<string> words(n);
  for(int i = 0; i < n; i++) {
    cin>>words[i];
  }

  int idx1, idx2, lastIdx = 0;
  vector<vector<int>> v(n);

  for(int i = 0; i < n-1; i++) {
    cin>>idx1>>idx2;
    idx1--;
    idx2--;
    v[idx1].push_back(idx2);
    lastIdx = idx1;
  }

  dfs(v, words, lastIdx);
  cout<<endl;

  return 0;
}