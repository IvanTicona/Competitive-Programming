#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;
typedef stack<pi> sp;
typedef vector<string> vs;

int f[] = {0, 1, 0, -1};
int c[] = {1, 0, -1, 0};

vs maze(502);

int lf;
int lc;

bool valid(int i, int j){
  return (i>=0&&j>=0&&i<lf&&j<lc);
}

void dfs(pi inicio, int &count){
  if(!valid(inicio.first, inicio.second)||maze[inicio.first][inicio.second]!='.') return;
  maze[inicio.first][inicio.second]='-';
  count++;
  for (int i = 0; i < 4; i++){
    int ni = inicio.first + f[i];
    int nj = inicio.second + c[i];
    if(!valid(ni,nj)||maze[ni][nj]!='.') continue;
    dfs({ni,nj}, count);
  }
}

void walls(pi inicio, int &w){
  if(!valid(inicio.first, inicio.second)||maze[inicio.first][inicio.second]!='-') return;
  if(w>0) {maze[inicio.first][inicio.second]='.'; w--;}
  else maze[inicio.first][inicio.second]='X';

  for (int i = 0; i < 4; i++){
    int ni = inicio.first + f[i];
    int nj = inicio.second + c[i];
    if(!valid(ni,nj)||maze[ni][nj]!='-') continue;
    walls({ni,nj}, w);
  }
}


int main(){

  int n, m, k;
  cin>>n>>m>>k;
  lf=n;lc=m;
  for (int i = 0; i < n; i++) cin>>maze[i];

  int count=0;
  pi init;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if(maze[i][j]=='.'){
        init={i,j};
        dfs({i,j}, count);
        i=n;j=m;
      }
    }
  }
  count-=k;
  // cout<<count<<endl;
  walls(init, count);

  for (int i = 0; i < n; i++) cout<<maze[i]<<endl;

  return 0;
}

