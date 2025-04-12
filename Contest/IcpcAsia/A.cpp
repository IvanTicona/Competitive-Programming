#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int r, c;
  cin >> r >> c;
  vector<string> grid(r);
  for (int i = 0; i < r; i++){
    cin >> grid[i];
  }
  
  vector<int> row(r, 0), col(c, 0);
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      if (grid[i][j] == '.'){
        row[i]++;
        col[j]++;
      }
    }
  }

  ll res = 0;
  
  for (int i = 0; i < r; i++){
    if (row[i] < 2) continue;
    __int128 sumA = 0, sumA2 = 0;
    for (int j = 0; j < c; j++){
      if (grid[i][j] == '.'){
        __int128 A = row[i] + col[j] - 3;
        sumA += A;
        sumA2 += A * A;
      }
    }
    __int128 totalPairs = sumA * sumA - sumA2;
    totalPairs -= (__int128)row[i] * (row[i] - 1) * (row[i] - 2);
    res += (ll)totalPairs;
  }
  
  for (int j = 0; j < c; j++){
    if (col[j] < 2) continue;
    __int128 sumB = 0, sumB2 = 0;
    for (int i = 0; i < r; i++){
      if (grid[i][j] == '.'){
        __int128 B = row[i] + col[j] - 3;
        sumB += B;
        sumB2 += B * B;
      }
    }
    __int128 totalPairs = sumB * sumB - sumB2;
    totalPairs -= (__int128)col[j] * (col[j] - 1) * (col[j] - 2);
    res += (ll)totalPairs;
  }
  
  cout << res << endl;

  return 0;
}