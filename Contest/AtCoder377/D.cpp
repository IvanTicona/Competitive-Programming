/*
Author: Ivan Ticona
*/
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N, M; cin >> N >> M;
  
  vector<ii> intervals(N);

  for (int i = 0; i < N; i++)
  {
    int L, R; cin >> L >> R;
    intervals[i] = {L, R};
  }

  int count = 0;

  for (int l = 1; l <= M; l++)
  {
    for (int r = l; r <= M; r++)
    {
      bool isValid = true;

      for (auto &interval: intervals)
      {
        int Li = interval.first;
        int Ri = interval.second;

        if (l <= Li && r >= Ri)
        {
          isValid = false;
          break;
        }
      }

      if (isValid)
      {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}