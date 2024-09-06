#include<bits/stdc++.h>

using namespace std;

int memo[100][100];
int N;
int W[100] = {1, 1, 1, 1, 1}, V[5]={1, 2, 2, 3, 6};

int dp(int id, int remW) {
  if ((id == N) || (remW == 0)) return 0; // two base cases
  int &ans = memo[id][remW];
  if (ans != -1) return ans; // computed before
  if (W[id] > remW) return ans = dp(id+1, remW); // no choice, skip
  return ans = max(dp(id+1, remW), // has choice, skip
  V[id]+dp(id+1, remW-W[id])); // or take
}

int main(){

  memset(memo, -1, sizeof(memo));
  cout<<dp(0, 4);

  return 0;
}