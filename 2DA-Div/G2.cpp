#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

using namespace std;

int mod5(int money)
{
  int n = 0;
  if (money % 10 == 0)
    n = (money - 20) / 15 + 2;
  else
    n = (money - 35) / 15 + 3;
  return n;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    bool yaEsta = false;
    int money = 0, n = 0;
    cin >> money;
    if ((money % 15 == 1 || money % 15 == 3 || money % 15 == 6 || money % 15 == 10))
    {
      n = money / 15 + 1;
      yaEsta = true;
    }
    if ((money % 15 == 14))
    {
      n = money / 15 + 3;
      yaEsta = true;
    }
    if ((money % 15 == 2 || money % 15 == 4 || money % 15 == 7 || money % 15 == 9 || money % 15 == 11 || money % 15 == 12 || money % 15 == 13) && !yaEsta)
    {
      n = money / 15 + 2;
    }
    if (money % 15 == 0 && !yaEsta)
    {
      n = money / 15;
      yaEsta = true;
    }
    if (money % 15 == 5 && !yaEsta)
    {
      if (money != 5)
      {
        n = mod5(money);
      }
      else
        n = 3;
      yaEsta = true;
    }
    if (money % 15 == 8 && !yaEsta)
    {
      if (money != 8)
      {
        n = mod5(money - 3) + 1;
      }
      else
        n = 3;
      yaEsta = true;
    }
    std::cout << n << std::endl;
  }

  return 0;
}