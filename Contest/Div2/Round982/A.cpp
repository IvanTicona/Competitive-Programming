/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

char grid[110][110];

int x[] = {1,0,-1,0}; 
int y[] = {0,1,0,-1};

int p;

void dfs(int i, int j){
  grid[i][j] = 'o';
  for (int h = 0; h < 4; h++)
  {
    int ni = i + y[h];
    int nj = j + x[h];
    if(ni < 0 || ni >= 110 || nj < 0 || nj >= 110) continue;
    if(grid[ni][nj] == '#') p++;
    if(grid[ni][nj] == '.') dfs(ni,nj);
  }
}

void draw(int w, int h){
  for (int i = 1; i <= w; i++)
  {
    for (int j = 1; j <= h; j++)
    {
      grid[i][j] = '#';
    }
  }
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;
  while (t--)
  {
    memset(grid, '.', sizeof(grid));
    int n; cin >> n;
    p = 0;
    for (int i = 0; i < n; i++)
    {
      int w, h; cin >> w >> h;
      draw(w,h);
    }
    dfs(0,0);

    cout << p << endl;
  }

  return 0;
}