/*
Author: Ivan Ticona
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t;
  cin >> t;
  while (t--)
  {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int x = 0, y = 0;
    int ts = 100;
    while(ts--)
    {
      for (int i = 0; i < n; i++)
      {
        if (s[i] == 'N') y += 1;
        else if (s[i] == 'E') x += 1;
        else if (s[i] == 'W') x -= 1;
        else if (s[i] == 'S') y -= 1;
        if (x == a && y == b)
        {
          cout << "YES" << endl;
          break;
        }
      }
      if (x == a && y == b) break;
    }
    if (x == a && y == b) continue;
    cout << "NO" << endl;
  }

  return 0;
}