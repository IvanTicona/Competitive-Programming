/*
Author: Ivan Ticona
*/
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

    vector<int> permutation(n);
    int k = 0;

    if (n % 2 == 1)
    {
      for (int i = 0; i < n; ++i)
      {
        if (i % 2 == 0)
        {
          permutation[i] = i + 2; // Números pares
        }
        else
        {
          permutation[i] = i; // Números impares
        }
      }
      permutation[n - 1] = n; // Asegurar que el último número sea n
      k = n;                  // k para n impar es n
    }
    else
    {
      for (int i = 0; i < n; ++i)
      {
        if (i % 2 == 0)
        {
          permutation[i] = i + 2; // Números pares
        }
        else
        {
          permutation[i] = i; // Números impares
        }
      }
      permutation[n - 1] = n;            // Último número n
      k = (1 << ((int)log2(n) + 1)) - 1; // k para n par
    }

    cout << k << endl;

    for (int num : permutation)
    {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}