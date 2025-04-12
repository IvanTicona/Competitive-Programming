#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
 
int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int R, C, n, p;
  cin >> R >> C >> n >> p;
  
  vvi grid(R, vi (C));
  vector<ii> pos(n+1);
  
  for (int i = 0; i < R; i++){
    for (int j = 0; j < C; j++){
      cin >> grid[i][j];
      int traveler = grid[i][j];
      if(traveler != 0){
        pos[traveler] = {i, j};
      }
    }
  }
  
  vvi S(n+1);
  
  int x[4] = {-1, 1, 0, 0};
  int y[4] = {0, 0, -1, 1};
  
  for (int i = 1; i <= n; i++){
    int r = pos[i].first;
    int c = pos[i].second;
    for (int k = 0; k < 4; k++){
      int nr = r + x[k];
      int nc = c + y[k];
      if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
      int j = grid[nr][nc];
      if(j != 0 && j > i){
        int d = j - i;
        S[d].push_back(i);
      }
    }
  }
  
  for (int d = 1; d < n; d++){
    if(!S[d].empty()){
      sort(all(S[d]));
    }
  }
  
  int count = 0;
  for (int q = 1; q <= n; q++){
    if(q == p) continue;
    if(q > p) {
      int d = q - p;
      if(!S[d].empty() && S[d][0] <= p) count++;
    } else {
      int d = p - q;
      if(!S[d].empty() && S[d][0] <= p - d) count++;
    }
  }
  
  cout << count << "/" << (n - 1) << "\n";
  
  return 0;
}
