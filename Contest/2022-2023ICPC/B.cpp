/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;

int grid[110][110];


int vx[] = {1, 0, -1, 0};
int vy[] = {0, 1, 0, -1};

bool visitados[102][102];
int li, lj;

int cnt = 0;

void dfs(int i, int j){
  visitados[i][j] = true;
  for (int h = 0; h < 4; h++)
  {
    int ni = i +vx[h];
    int nj = j +vy[h];
    if(ni < 0 || ni >= li || nj < 0 || nj >= lj) continue;
    if(grid[ni][nj] > grid[i][j] && !visitados[ni][nj]){
      cnt++;      
      dfs(ni, nj);
    }
  }
}


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  int R, C; cin >> R >> C;
  li = R, lj = C;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cin >> grid[i][j];
    }
  }
  priority_queue<int, vector<int>, less<int>> colita;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cnt = 1;
      memset(visitados, false, sizeof(visitados)); 
      dfs(i,j); 
      colita.push(cnt);
    }
    
  }
  cout<<colita.top()<<endl;



  return 0;
}