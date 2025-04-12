#include <bits/stdc++.h>

using namespace std;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  vector<int> P(n+1);
  for (int i = 1; i <= n; i++){
    int label = a[i];
    P[label] = i;
  }
  
  const int INF = 1e9;
  vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
  
  for (int len = 2; len <= n; len++){
    for (int i = 1; i <= n - len + 1; i++){
      int j = i + len - 1;
      dp[i][j] = 1e9;
      for (int k = i; k < j; k++){
        int cost = abs(P[k+1] - P[i]);
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + cost);
      }
    }
  }
  
  cout << dp[1][n] << "\n";

  return 0;
}
