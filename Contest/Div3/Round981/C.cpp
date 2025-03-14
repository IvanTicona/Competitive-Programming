#include <bits/stdc++.h>

using namespace std;

int calculateDisturbance(const vector<int> &a, int n)
{
  int disturbance = 0;
  for (int i = 1; i < n; ++i)
  {
    if (a[i] == a[i - 1])
    {
      ++disturbance;
    }
  }
  return disturbance;
}

int minimizeDisturbance(vector<int> &a, int n)
{
  int disturbance = calculateDisturbance(a, n);

  for (int i = 0; i < n / 2; ++i)
  {
    if (a[i] != a[n - i - 1])
    {
      swap(a[i], a[n - i - 1]);

      int newDisturbance = calculateDisturbance(a, n);

      if (newDisturbance >= disturbance)
      {
        swap(a[i], a[n - i - 1]);
      }
      else
      {
        disturbance = newDisturbance;
      }
    }
  }

  return disturbance;
}

int main()
{

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
      cin >> a[i];
    }

    cout << minimizeDisturbance(a, n) << endl;
  }

  return 0;
}
