#include <bits/stdc++.h>

using namespace std;

int main()
{

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
    }

    unordered_map<long long, int> m;
    long long sum = 0;
    int last = -1;
    int cnt = 0;

    m[0] = -1;

    for (int i = 0; i < n; ++i)
    {
      sum += a[i];

      if (m.find(sum) != m.end())
      {
        if (m[sum] >= last)
        {
          cnt++;
          last = i;
        }
      }
      m[sum] = i;
    }

    cout << cnt << endl;
  }

  return 0;
}
