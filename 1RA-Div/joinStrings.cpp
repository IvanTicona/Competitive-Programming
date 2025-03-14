#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<string> vs;

void dfs(vvi &grafo, vs &s, int idx) {
  cout << s[idx];
  for(int i: grafo[idx]) {
    dfs(grafo, s, i);
  }
}

int main() {

  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int n; cin >> n;
  vs words(n);
  for(int i = 0; i < n; i++) {
    cin >> words[i];
  }

  int idx1, idx2, lastIdx = 0;
  vvi grafo(n);

  for(int i = 0; i < n-1; i++) {
    cin >> idx1 >> idx2;
    idx1--;
    idx2--;
    grafo[idx1].push_back(idx2);
    lastIdx = idx1;
  }

  dfs(grafo, words, lastIdx);
  cout << endl;

  return 0;
}