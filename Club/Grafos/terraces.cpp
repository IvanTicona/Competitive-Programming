#include<bits/stdc++.h>

using namespace std;

vector<int> garden[505];
int vis[505][505];

typedef pair<int,int> Cell;

int lf,lc;
int rice=0;

int x[]={0,0,1,-1};
int y[]={1,-1,0,0};

void bfs(Cell cell){
  bool pit=false;
  int cells=0;
  queue<Cell> cola;
  cola.push(cell);
  while (!cola.empty()){
    Cell adjCell=cola.front();
    cola.pop();
    if(vis[adjCell.first][adjCell.second]) continue;
    vis[adjCell.first][adjCell.second]=true;
    cells++;
    for (int i = 0; i < 4; i++){
      int nf=adjCell.first+x[i];
      int nc=adjCell.second+y[i];
      if(nf<0||nf>=lf||nc<0||nc>=lc) continue;
      if(!vis[nf][nc]&&garden[adjCell.first][adjCell.second]==garden[nf][nc]){
        Cell vec(nf,nc);
        cola.push(vec);
      }
      if(garden[nf][nc]<garden[adjCell.first][adjCell.second]){
        pit=true;
      }
    }
  }
  if(!pit){
    rice+=cells;
  }
}

int main(){

  int x, y;
  cin>>x>>y;
  memset(garden, 0, sizeof(garden));
  lf=y;
  lc=x;
  for (int i = 0; i < y; i++){
    for (int j = 0; j < x; j++){
      int a;
      cin>>a;
      garden[i].push_back(a);
    }
  }
  for (int i = 0; i < y; i++){
    for (int j = 0; j < x; j++){
      if(vis[i][j]) continue;
      Cell cell(i,j);
      bfs(cell);
    }
  }
  cout<<rice<<endl;

  return 0;
}