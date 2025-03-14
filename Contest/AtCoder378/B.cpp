/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N; cin >> N;
  vector<int> q(N), r(N);
  for (int i = 0; i < N; i++) cin >> q[i] >> r[i];

  int Q; cin >> Q;
  for (int i = 0; i < Q; i++)
  {
    int t, d; cin >> t >> d;
    // if(d%q[t] == r[t]) 
  }

  return 0;
}