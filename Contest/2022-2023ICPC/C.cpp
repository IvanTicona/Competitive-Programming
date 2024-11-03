#include <bits/stdc++.h>

using namespace std;

#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)

const int MAXN = 1010;
bool dp[MAXN][MAXN];

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, k, e;
  cin >> n >> k >> e;
  int l = e, r = n - k - e;

  dp[0][0] = 1;
  for(int len = 1; len < n + 1; len++){
    if (len != k){
      for (int i = l; i >= 0; i--){
        for (int j = r; j >= 0; j--){
          if (len <= i) dp[i][j] |= dp[i - len][j];
          if (len <= j) dp[i][j] |= dp[i][j - len];
        }
      }
    }
  }

  int ans = k;
  for(int i = 0; i < l + 1; i++){
    for(int j = 0; j < r + 1; j++){
      if (dp[i][j]){
        ans = max(ans, i + j + k);
      }
    }
  }

  cout << n - ans << "\n";
}