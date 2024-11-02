#include <bits/stdc++.h>

#define fore(i, a, b) for (int i = a, ThxDem = b; i < ThxDem; ++i)

using namespace std;

const int MAXN = 1010;
bool dp[MAXN][MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, k, e;
  cin >> n >> k >> e;
  int l = e, r = n - k - e;

  dp[0][0] = 1;
  fore(len, 1, n + 1) if (len != k)
  {
    for (int i = l; i >= 0; i--)
      for (int j = r; j >= 0; j--)
      {
        if (len <= i)
          dp[i][j] |= dp[i - len][j];
        if (len <= j)
          dp[i][j] |= dp[i][j - len];
      }
  }

  int ans = k;
  fore(i, 0, l + 1) fore(j, 0, r + 1) if (dp[i][j])
  {
    ans = max(ans, i + j + k);
  }

  cout << n - ans << "\n";
}