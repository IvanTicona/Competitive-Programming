#include <bits/stdc++.h>

using namespace std;

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
    string s;
    cin >> s;
    bool win = false;
    if (s[0] == '1' || s[n - 1] == '1')
    {
      win = true;
    }
    for (int i = 1; i < n; i++)
    {
      if (s[i - 1] == '1' && s[i] == '1')
      {
        win = true;
        break;
      }
    }
    if (win)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}