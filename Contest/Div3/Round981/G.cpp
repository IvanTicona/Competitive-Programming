/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

vector<int> graph[200010];

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;
    for (int i = 0; i < n-2; i++)
    {
      int a, b; cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    int q; cin >> q;

    while (q--)
    {
      int v, k; cin >> v >> k;

    }
  }

  return 0;
}