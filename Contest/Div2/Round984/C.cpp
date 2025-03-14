/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

set<int> find_pattern_indices(const string &s, const string &pattern)
{
  set<int> indices;
  int n = s.size(), m = pattern.size();
  for (int i = 0; i <= n - m; i++)
  {
    if (s.substr(i, m) == pattern)
    {
      indices.insert(i);
    }
  }
  return indices;
}


void update_pattern_indices(string &s, set<int> &pattern_indices, int pos, const string &pattern)
{
  int m = pattern.size();
  int n = s.size();

  for (int i = max(0, pos - m + 1); i <= min(n - m, pos + m - 1); i++)
  {
    if (pattern_indices.count(i) && s.substr(i, m) != pattern)
    {
      pattern_indices.erase(i);
    }
    if (!pattern_indices.count(i) && s.substr(i, m) == pattern)
    {
      pattern_indices.insert(i);
    }
  }
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;

  while (t--)
  {
    string s; cin >> s;
    int q; cin >> q;

    string pattern = "1100";
    set<int> pattern_indices = find_pattern_indices(s, pattern);

    while (q--)
    {
      int i; char v; cin >> i >> v;
      i--;
      s[i] = v;

      update_pattern_indices(s, pattern_indices, i, pattern);

      if (!pattern_indices.empty()){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}
